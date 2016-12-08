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
    
    // If you want logging from the engine, uncomment this code:
//     FIFE::LogManager* logManager {engine->getLogManager()};
//     logManager->setLogToPrompt(true);
//     logManager->setLevelFilter(FIFE::LogManager::LEVEL_DEBUG);
//     logManager->addVisibleModule(LM_CONTROLLER);
//     
//     // Add logging from all modules
//     for (int i {0}; i < logmodule_t::LM_MODULE_MAX; i++)
//     {
//         logManager->addVisibleModule(static_cast<logmodule_t>(i));
//     }
}

FIFEFacade::~FIFEFacade() {
    delete btnOptions;
    delete btnExit;
    delete engine;
    delete keyListener;
    delete mouseListener;
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

void FIFEFacade::setFPSLimit(int fpsLimit)
{
    engine->getSettings().setFrameLimit(fpsLimit);
    engine->getSettings().setFrameLimitEnabled(true);
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

    engine->setGuiManager(guimanager);
    engine->getEventManager()->addSdlEventListener(guimanager);

    initInput();

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
    ///What does this do?
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
            fifeCamera->initView();
        }

        // done with map loader safe to delete
        delete mapLoader;
        mapLoader = 0;
    }

    mouseListener->setCamera(fifeCamera);

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
        mouseListener = new FIFEMouseListener(game, fifeCamera);
        engine->getEventManager()->addKeyListener(keyListener);
        engine->getEventManager()->addMouseListener(mouseListener);
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

void FIFEFacade::move(std::string name, double x, double y) {
    if (map) {
        FIFE::Layer *layer = map->getLayer("TechdemoMapGroundObjectLayer");

        if (layer) {
            FIFE::Instance *instance = layer->getInstance(name);

            if (instance) {
                ///Keep this for now
                // move controller to clicked spot
                FIFE::Location destination(instance->getLocation());
                FIFE::ScreenPoint screenPoint(x, y);
                if(fifeCamera->Camera() != nullptr){
                    FIFE::ExactModelCoordinate mapCoords = fifeCamera->Camera()->toMapCoordinates(screenPoint, false);
                    mapCoords.z = 0.0;
                    destination.setMapCoordinates(mapCoords);
                    std::cout << "X: " << mapCoords.x << ", Y:" << mapCoords.y << std::endl;
                    instance->move("walk", destination, instance->getTotalTimeMultiplier());
                }
            }
        }
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

void FIFEFacade::updateLocation(int x, int y) {
    fifeCamera->updateLocation(x,y);
}

void FIFEFacade::tick()
{
    keyListener->tick();
}


std::vector<std::string> FIFEFacade::loadTowers()
{
    FIFE::Layer* layer = map->getLayer("unitLayer");
    std::vector<std::string> idList;
    if(layer)
    {
        std::vector<FIFE::Instance*> instances = layer->getInstances();

        //get the towers
        for (unsigned int i = 0; i < instances.size(); ++i)
        {
            //select instances with tower in their id
            std::string id = instances.at(i)->getId();

            if(id.find("Tower")  != std::string::npos)
            {
                idList.push_back(id);
            }
        }
    }

    return idList;


}
