#include "FIFEFacade.h"
#include "GUI/FIFEChanGuiManager.h"


FIFEFacade::FIFEFacade(IGame* game)
    : game{game}
{
    this->engine = new FIFE::Engine();
    this->fifeChan = new FIFEChan(this->engine);

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
    delete engine;
    delete keyListener;
    delete mouseListener;
    delete fifeCamera;
    delete fifeChan;
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
    settings.setWindowTitle(title);                                 // Doesn't work very well, that's why we manually use SDL below. Bad FIFE!

    SDL_SetWindowTitle(engine->getRenderBackend()->getWindow(), title.c_str());
}

AGUIManager* FIFEFacade::createGUIManager() {
    return new FIFEChanGuiManager();
}

void FIFEFacade::setActiveGUIManager(AGUIManager* manager) {
    if(this->guimanager != nullptr)
        this->fifeChan->getGuiManager()->remove(this->guimanager->getContainer());

    this->guimanager = static_cast<FIFEChanGuiManager*>(manager);
    this->fifeChan->getGuiManager()->add(this->guimanager->getContainer());
    this->engine->getEventManager()->addSdlEventListener(this->fifeChan->getGuiManager());
}

void FIFEFacade::setFPSLimit(int fpsLimit)
{
    engine->getSettings().setFrameLimit(fpsLimit);
    engine->getSettings().setFrameLimitEnabled(true);
}

void FIFEFacade::init()
{
    this->engine->init();
    this->fifeChan->init();

    this->initInput();

    this->engine->getEventManager()->addSdlEventListener(this->fifeChan->getGuiManager());
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

void FIFEFacade::deleteInstance(std::string instanceName){
    if (map) {
        FIFE::Layer* layer {map->getLayer("unitLayer")};
        if (layer) {
            FIFE::Instance* instance {layer->getInstance(instanceName)};
            if (instance) {
                layer->deleteInstance(instance);
            }
        }
    }
}

void FIFEFacade::removeInstance(std::string instanceName){
    if (map) {
        FIFE::Layer* layer {map->getLayer("unitLayer")};
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
