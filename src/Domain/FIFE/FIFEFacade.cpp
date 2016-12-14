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

void FIFEFacade::setRenderBackend(std::string engine)
{
    FIFE::EngineSettings& settings = this->engine->getSettings();
    settings.setRenderBackend(engine);
}

const uint16_t FIFEFacade::getScreenWidth() {
    FIFE::EngineSettings& settings = engine->getSettings();
    return settings.getScreenWidth();
}

const uint16_t FIFEFacade::getScreenHeight() {
    FIFE::EngineSettings& settings = engine->getSettings();
    return settings.getScreenHeight();
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

    //initialize the audio
    fifeAudio = new FIFEAudio(engine->getSoundClipManager(), engine->getSoundManager());

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

bool FIFEFacade::instanceExists(std::string name, std::string layerName = "unitLayer") {
    if (map) {
        FIFE::Layer *layer = map->getLayer(layerName);

        if (layer) {
            FIFE::Instance *instance = layer->getInstance(name);

            if (instance) {
                return true;
            }
        }
    }

    return false;
}

double FIFEFacade::getInstanceX(std::string name, std::string layerName) {
    if (this->instanceExists(name, layerName)) {
        FIFE::Layer *layer = map->getLayer(layerName);
        FIFE::Instance *instance = layer->getInstance(name);

        return instance->getLocation().getMapCoordinates().x;
    }

    return 0;
}

double FIFEFacade::getInstanceY(std::string name, std::string layerName) {
    if (this->instanceExists(name, layerName)) {
        FIFE::Layer *layer = map->getLayer(layerName);
        FIFE::Instance *instance = layer->getInstance(name);

        return instance->getLocation().getMapCoordinates().y;
    }

    return 0;
}

void FIFEFacade::move(std::string name, double x, double y, int moveSpeed) {
    if (map) {
        FIFE::Layer* layer = map->getLayer("unitLayer");

        if (layer) {
            FIFE::Instance* instance = layer->getInstance(name);

            if (instance) {
                ///Keep this for now
                // move controller to clicked spot
                FIFE::Location destination(instance->getLocation());
                FIFE::ScreenPoint screenPoint(x, y);
                if(fifeCamera->camera() != nullptr){
                    FIFE::ExactModelCoordinate mapCoords = fifeCamera->camera()->toMapCoordinates(screenPoint, false);
                    mapCoords.z = 0.0;
                    destination.setMapCoordinates(mapCoords);
                    instance->move("walk", destination, moveSpeed);
                }
            }
        }
    }
}

std::string FIFEFacade::createInstance(std::string objectName, std::string instanceName, double x, double y){
    if(map){
        FIFE::Layer* layer {map->getLayer("unitLayer")};
        if(layer)  {
            FIFE::Object* object {engine->getModel()->getObject(objectName, "grimwall")};
            if(object) {
                FIFE::ExactModelCoordinate mapCoords{};
                mapCoords.x = x;
                mapCoords.y = y;
                mapCoords.z = 0.0;
                FIFE::Location* location {new FIFE::Location(layer)};
                location->setMapCoordinates(mapCoords);
                //Check if position is occupied
                if(layer->getInstancesAt(*location).size() == 0) {
                    layer->createInstance(object, mapCoords, instanceName);
                }
                delete location;
                return instanceName;
            }
        }
    }
    return "ERROR";
}

void FIFEFacade::deleteInstance(std::string instanceName, std::string layerName){
    if (map) {
        FIFE::Layer* layer {map->getLayer(layerName)};
        if (layer) {
            FIFE::Instance* instance {layer->getInstance(instanceName)};
            if (instance) {
                layer->deleteInstance(instance);
            }
        }
    }
}

void FIFEFacade::removeInstance(std::string instanceName, std::string layerName){
    if (map) {
        FIFE::Layer* layer {map->getLayer(layerName)};
        if (layer) {
            FIFE::Instance* instance {layer->getInstance(instanceName)};
            if (instance) {
                layer->removeInstance(instance);
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
    mouseListener->tick();
}

std::vector<UnitManager<ATower>*> FIFEFacade::loadTowers()
{
    FIFE::Layer* layer = map->getLayer("towerLayer");
    std::vector<UnitManager<ATower>*> towers;
    if(layer)
    {
        std::vector<FIFE::Instance*> instances = layer->getInstances();

        //get the towers
        for (unsigned int i = 0; i < instances.size(); ++i)
        {
            //select instances with tower in their id
            std::string id = instances.at(i)->getId();

            if(id.find("Tower") != std::string::npos)
            {
                double x = instances.at(i)->getLocation().getMapCoordinates().x;
                double y = instances.at(i)->getLocation().getMapCoordinates().y;

                UnitManager<ATower>* tower = generateTower(id, x, y);
                if (tower != nullptr) {
                    towers.push_back(tower);
                }
            }
        }
    }

    return towers;


}
