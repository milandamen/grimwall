 
#include "FIFEFacade.h"

FIFEFacade::FIFEFacade(IGame* game)
{
    this->game = game;
    engine = new FIFE::Engine();
    guimanager = new FIFE::FifechanManager();

    fs::path defaultFontPath("assets/fonts/FreeSans.ttf");
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setBitsPerPixel(0);
    settings.setInitialVolume(5.0);
    settings.setWindowTitle("Grimwall v0.1");
    settings.setDefaultFontGlyphs("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&amp;`'*#=[]\"");
    settings.setDefaultFontPath(defaultFontPath.string());

    // FIFE::FifechanManager* guiManager = static_cast<FIFE::FifechanManager*>(m_engine->getGuiManager());
}

FIFEFacade::~FIFEFacade() {
    delete engine;
    delete guimanager;
    delete keyListener;
    delete fifeCamera;
}

FIFE::FifechanManager* FIFEFacade::getGuiManager()
{
    return guimanager;
}

void FIFEFacade::setRenderBackend(std::string engine)
{
    FIFE::EngineSettings& settings = this->engine->getSettings();
    settings.setRenderBackend(engine);
}

void FIFEFacade::setScreenWidth(int width)
{
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setScreenWidth(width);
}

void FIFEFacade::setScreenHeight(int height)
{
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setScreenHeight(height);
}

void FIFEFacade::setFullScreen(bool fullScreen)
{
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setFullScreen(fullScreen);
}

void FIFEFacade::setWindowTitle(std::string title)
{
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setWindowTitle(title);                                 // Doesn't work very well, that's why we manually use SDL below.
    
    SDL_SetWindowTitle(engine->getRenderBackend()->getWindow(), title.c_str());
}

void FIFEFacade::init()
{
    engine->init();

    // setup the gui
    guimanager->setDefaultFont(
            engine->getSettings().getDefaultFontPath(),
            engine->getSettings().getDefaultFontSize(),
            engine->getSettings().getDefaultFontGlyphs()
    );

    guimanager->init(
            engine->getRenderBackend()->getName(),
            engine->getRenderBackend()->getScreenWidth(),
            engine->getRenderBackend()->getScreenHeight()
    );

    initInput();

    engine->setGuiManager(guimanager);
    engine->getEventManager()->addSdlEventListener(guimanager);

    btnOptions = new fcn::Button();
    btnOptions->setId("btnOptions");
    btnOptions->setActionEventId("clickBtnOptions");
    btnOptions->setWidth(300);
    btnOptions->setHeight(50);
    btnOptions->setPosition(300, 200);
    btnOptions->setCaption("Play");
    btnOptions->addActionListener(this);
    btnOptions->addMouseListener(this);
    guimanager->add(btnOptions);

    btnExit = new fcn::Button();
    btnExit->setId("btnExit");
    btnExit->setActionEventId("clickBtnExit");
    btnExit->setWidth(300);
    btnExit->setHeight(50);
    btnExit->setPosition(300, 300);
    btnExit->setCaption("Quit to desktop");
    btnExit->addActionListener(this);
    btnExit->addKeyListener(this);
    btnExit->addMouseListener(this);
    guimanager->add(btnExit);
}

void FIFEFacade::mousePressed(fcn::MouseEvent& mouseEvent)
{
    if(mouseEvent.getSource() == btnOptions) {
        guimanager->getTopContainer()->setVisible(false);
    } else {
        game->quit();
    }

}

void FIFEFacade::keyPressed(fcn::KeyEvent &keyEvent)
{
    std::cout << keyEvent.getDistributor();
//    if(actionEvent.getId() == "clickBtnOptions")
//        std::cout << "Play!";
//    else
//        std::cout << "Exit!";
}

void FIFEFacade::action(const fcn::ActionEvent &actionEvent)
{
    std::cout << actionEvent.getId();
    if(actionEvent.getId() == "clickBtnOptions")
        std::cout << "Play!";
    else
        std::cout << "Exit!";
}

void FIFEFacade::loadMap(std::string path)
{
    if(map){
        delete fifeCamera;
    }

    if (engine->getModel() && engine->getVFS() && engine->getImageManager() && 
        engine->getRenderBackend())
    {
        // create the default loader for the FIFE map format
        //FIFE::DefaultMapLoader* mapLoader = FIFE::createDefaultMapLoader(engine->getModel(), engine->getVFS(), 
        //  engine->getImagePool(), engine->getAnimationPool(), engine->getRenderBackend());
        FIFE::MapLoader* mapLoader = new FIFE::MapLoader(engine->getModel(), engine->getVFS(), 
            engine->getImageManager(), engine->getRenderBackend());

        fs::path mapPath(path);

        if (mapLoader) {
            // load the map
            map = mapLoader->load(mapPath.string());
            fifeCamera = new FIFECamera(map, engine->getEventManager(), engine->getTimeManager());
        }

        // done with map loader safe to delete
        delete mapLoader;
        mapLoader = 0;
    }
    
    initView();
    
    if (!pumpingInitialized)
    {
        pumpingInitialized = true;
        engine->initializePumping();
    }
}

void FIFEFacade::initView()
{
    fifeCamera->initView();
}

void FIFEFacade::initInput()
{
    if(engine->getEventManager() && engine->getModel())
    {
        // attach our key listener to the engine
        keyListener = new FIFEKeyListener(game);
        engine->getEventManager()->addKeyListener(keyListener);
    }
}

void FIFEFacade::render()
{
    engine->pump();
}

int FIFEFacade::getFPS()
{
    if (engine == nullptr || !pumpingInitialized) { return 0; }
    
    return static_cast<int>(1000/engine->getTimeManager()->getAverageFrameTime());
}

int FIFEFacade::getTime()
{
    return engine->getTimeManager()->getTime();
}

void FIFEFacade::setInstanceLocation(std::string name, double x, double y) {
    if (map) {
        FIFE::Layer *layer = map->getLayer("unitLayer");

        if (layer) {
            FIFE::Instance *instance = layer->getInstance(name);

            if (instance) {
                // Get the current location of the instance
                FIFE::Location destination(instance->getLocation());

                FIFE::ExactModelCoordinate mapCoords{};
                mapCoords.x = x;
                mapCoords.y = y;
                mapCoords.z = 0.0;
                destination.setMapCoordinates(mapCoords);

                instance->setLocation(destination);
            }
        }
    }
}

std::string FIFEFacade::createInstance(std::string objectName, std::string instanceName, double x, double y){
    if(map){
        FIFE::Layer *layer = map->getLayer("unitLayer");
        if(layer)  {
            FIFE::Object *object = engine->getModel()->getObject(objectName, "grimwall");
            if(object) {
                std::cout << "Object created." << std::endl;
                FIFE::ExactModelCoordinate mapCoords{};
                mapCoords.x = x;
                mapCoords.y = y;
                mapCoords.z = 0.0;
                FIFE::Location *location = new FIFE::Location(layer);
                location->setMapCoordinates(mapCoords);
                    if(layer->getInstancesAt(*location).size() == 0) {
                        FIFE::Instance *instance = layer->createInstance(object, mapCoords, instanceName);
                        std::cout << "Instance added." << std::endl;
                    }
                    else {
                        std::cout << "ERROR: space occupied." << std::endl;
                    }
                delete location;
                return instanceName;
            }
            else {
                std::cout << "No object found." << std::endl;
            }
        }
        else {
            std::cout << "No layer found." << std::endl;
        }
    }
    else {
        std::cout << "No map found." << std::endl;
    }
}

void FIFEFacade::registerCallback(std::string keys, ICallback* callback)
{
    keyListener->registerCallback(keys, callback);
}

void FIFEFacade::zoomIn() {
    fifeCamera->zoomIn();
}

void FIFEFacade::zoomOut() {
    fifeCamera->zoomOut();
}

void FIFEFacade::updateLocation(std::string location) {
    fifeCamera->updateLocation(location);
}


