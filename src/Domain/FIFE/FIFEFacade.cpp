#include "FIFEFacade.h"

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
    settings.setScreenWidth(1024);
    settings.setScreenHeight(768);
    settings.setDefaultFontGlyphs("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&amp;`'*#=[]\"");
    settings.setDefaultFontPath(defaultFontPath.string());

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
    delete fifeAudio;
}

void FIFEFacade::setRenderBackend(std::string engine)
{
    this->engine->getSettings().setRenderBackend(engine);
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
    this->engine->getSettings().getScreenWidth();
}

void FIFEFacade::setScreenHeight(int height)
{
    this->engine->getSettings().setScreenHeight(height);
}

void FIFEFacade::setFullScreen(bool fullScreen)
{
    this->engine->getSettings().setFullScreen(fullScreen);
}

void FIFEFacade::setWindowTitle(std::string title)
{
    this->engine->getSettings().setWindowTitle(title);
    // FIFE's setWindowTitle doesn't work very well, that's why we manually use SDL below. Bad FIFE!
    SDL_SetWindowTitle(this->engine->getRenderBackend()->getWindow(), title.c_str());
}

AGUIManager* FIFEFacade::createGUIManager() {
    return new FIFEChanGuiManager();
}

void FIFEFacade::setActiveGUIManager(AGUIManager* manager) {
    if(this->guimanager != nullptr) {
        this->fifeChan->getGuiManager()->remove(this->guimanager->getContainer());
    }

    this->guimanager = static_cast<FIFEChanGuiManager*>(manager);
    this->fifeChan->getGuiManager()->add(this->guimanager->getContainer());
    this->engine->getEventManager()->addSdlEventListener(this->fifeChan->getGuiManager());
}

void FIFEFacade::setFPSLimit(int fpsLimit)
{
    if (!this->initialized)
    {
        this->engine->getSettings().setFrameLimitEnabled(fpsLimit != 0);
        this->engine->getSettings().setFrameLimit(fpsLimit);
    }
    else
    {
        this->engine->getRenderBackend()->setFrameLimitEnabled(fpsLimit != 0);
        this->engine->getRenderBackend()->setFrameLimit(fpsLimit);
    }
}

void FIFEFacade::init()
{
    this->engine->init();
    this->fifeChan->init();
    //initialize the audio
    this->fifeAudio = new FIFEAudio(engine->getSoundClipManager(), engine->getSoundManager());
    this->initInput();

    this->engine->getEventManager()->addSdlEventListener(this->fifeChan->getGuiManager());
    
    this->initialized = true;
}

void FIFEFacade::loadMap(std::string path)
{
    if(this->fifeCamera != nullptr) {
        delete this->fifeCamera;
    }

    if (this->engine->getModel() && this->engine->getVFS() && this->engine->getImageManager() &&
        this->engine->getRenderBackend())
    {
        // create the default loader for the FIFE map format
        //FIFE::DefaultMapLoader* mapLoader = FIFE::createDefaultMapLoader(engine->getModel(), engine->getVFS(),
        //  engine->getImagePool(), engine->getAnimationPool(), engine->getRenderBackend());
        FIFE::MapLoader* mapLoader = new FIFE::MapLoader(this->engine->getModel(), this->engine->getVFS(),
                                                         this->engine->getImageManager(), this->engine->getRenderBackend());

        fs::path mapPath(path);

        if (mapLoader) {
            // load the map
            this->map = mapLoader->load(mapPath.string());
            this->fifeCamera = new FIFECamera(this->map, this->engine->getEventManager(), this->engine->getTimeManager());
            this->fifeCamera->initView();
        }

        // done with map loader safe to delete
        delete mapLoader;
    }

    this->mouseListener->setCamera(this->fifeCamera);

    if (!this->pumpingInitialized)
    {
        this->pumpingInitialized = true;
        this->engine->initializePumping();
    }

}

void FIFEFacade::initView()
{
    this->fifeCamera->initView();
}

void FIFEFacade::initInput()
{
    if(this->engine->getEventManager() && this->engine->getModel())
    {
        // attach our key listener to the engine
        this->keyListener = new FIFEKeyListener(this->game);
        this->mouseListener = new FIFEMouseListener(this->game, this->fifeCamera);
        this->engine->getEventManager()->addKeyListener(this->keyListener);
        this->engine->getEventManager()->addMouseListener(this->mouseListener);
    }
}

void FIFEFacade::render()
{
    this->engine->pump();
}

int FIFEFacade::getFPS()
{
    if (this->engine == nullptr || !this->pumpingInitialized) { return 0; }

    return static_cast<int>(1000/this->engine->getTimeManager()->getAverageFrameTime());
}

int FIFEFacade::getTime()
{
    return engine->getTimeManager()->getTime();
}

// Function to animate an instance only once
void FIFEFacade::setInstanceAction(std::string name, std::string action, std::string layerName) {
    // Initial checks if we can actually perform an animation on the instance
    if (map) {
        FIFE::Layer *layer = map->getLayer(layerName);

        if (layer) {
            FIFE::Instance *instance = layer->getInstance(name);

            if (instance) {
                // End of checks, now perform the animation.
                instance->actOnce(action);
            }
        }
    }
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


void FIFEFacade::move(std::string name, std::string layerName, double x, double y, int moveSpeed) {
    if (this->map) {
        FIFE::Layer* layer = this->map->getLayer(layerName);
        if (layer) {
            FIFE::Instance* instance = layer->getInstance(name);

            if (instance) {
                ///Keep this for now
                // move controller to clicked spot
                FIFE::Location destination(instance->getLocation());
                FIFE::ScreenPoint screenPoint(x, y);
                if(this->fifeCamera->camera() != nullptr){
                    FIFE::ExactModelCoordinate mapCoords = this->fifeCamera->camera()->toMapCoordinates(screenPoint, false);
                    mapCoords.z = 0.0;
                    destination.setMapCoordinates(mapCoords);
                    instance->move("walk", destination, moveSpeed);
                }
            }
        }
    }
}

std::string FIFEFacade::createInstance(std::string objectName, std::string instanceName, double x, double y){
    if(this->map){
        FIFE::Layer* layer {this->map->getLayer("unitLayer")};
        if(layer)  {
            FIFE::Object* object {this->engine->getModel()->getObject(objectName, "grimwall")};
            if(object) {
                FIFE::ModelCoordinate mapCoords{};
                mapCoords.x = x;
                mapCoords.y = y;
                mapCoords.z = 0.0;
                FIFE::Location* location {new FIFE::Location(layer)};
                location->setLayerCoordinates(mapCoords);
                
                // Check if position is occupied
                if(layer->getInstancesAt(*location).size() == 0 || layer->getInstancesAt(*location).at(0)->getId() == "spawnLocation") {
                    FIFE::Instance* instance {layer->createInstance(object, mapCoords, instanceName)};
                    FIFE::InstanceVisual::create(instance);
                    return instanceName;
                }
                else {
                    return "ERROR";
                }
            }
        }
    }
    return "ERROR";
}

void FIFEFacade::deleteInstance(std::string instanceName, std::string layerName){
    if (this->map) {
        FIFE::Layer* layer {this->map->getLayer(layerName)};
        if (layer) {
            FIFE::Instance* instance {layer->getInstance(instanceName)};
            if (instance) {
                layer->deleteInstance(instance);
            }
        }
    }
}

void FIFEFacade::removeInstance(std::string instanceName, std::string layerName){
    if (this->map) {
        FIFE::Layer* layer {this->map->getLayer(layerName)};
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
    this->keyListener->registerCallback(keys, callback);
}

void FIFEFacade::zoomIn() {
    this->fifeCamera->zoomIn();
}

void FIFEFacade::zoomOut() {
    this->fifeCamera->zoomOut();
}

void FIFEFacade::updateLocation(int x, int y) {
    this->fifeCamera->updateLocation(x,y);
}

void FIFEFacade::tick()
{
    this->keyListener->tick();
    this->mouseListener->tick();
}

std::vector<UnitManager<ATower>*> FIFEFacade::loadTowers()
{
    FIFE::Layer* layer = this->map->getLayer("towerLayer");
    std::vector<UnitManager<ATower>*> towers;
    TowerFactory factory;
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

                UnitManager<ATower>* tower = factory.createTower(id, x, y);
                if (tower != nullptr) {
                    towers.push_back(tower);
                }
            }
        }
    }

    return towers;
}

void FIFEFacade::playMusic(std::string asset) {
    fifeAudio->playMusic(asset);
}

void FIFEFacade::stopMusic() {
    fifeAudio->stopMusic();
}

void FIFEFacade::playSoundEffect(std::string asset) {
    fifeAudio->playSoundEffect(asset);
}

void FIFEFacade::stopSoundEffect() {
    fifeAudio->stopSoundEffect();
}

void FIFEFacade::stopAllMusic() {
    fifeAudio->stopAllSound();
}

void FIFEFacade::setVolume(int volume)
{
    this->fifeAudio->setVolume(volume);
}

int FIFEFacade::getVolume()
{
    return this->fifeAudio->getVolume();
}

std::vector<int> FIFEFacade::getHerospawnPoint() {
    std::vector<int> ret;
    ret.push_back(0);   // x
    ret.push_back(0);   // y
    ret.push_back(0);   // z
    
    FIFE::Layer* layer = this->map->getLayer("unitLayer");

    if(layer)
    {
        std::vector<FIFE::Instance*> instances = layer->getInstances();

        //get the towers
        for (unsigned int i = 0; i < instances.size(); ++i)
        {
            //select instances with tower in their id
            if(instances.at(i)->getId() == "spawnLocation")
            {
                FIFE::ModelCoordinate heroPoint = instances.at(i)->getLocation().getLayerCoordinates();
                ret.clear();
                ret.push_back(heroPoint[0]);
                ret.push_back(heroPoint[1]);
                ret.push_back(heroPoint[2]);
                break;
            }
        }
    }

    return ret;
}

void FIFEFacade::drawBox(double x1, double y1, double x2, double y2){
    engine->getRenderBackend()->fillRectangle(FIFE::Point(x1, y1), (x2 - x1), (y2 - y1), 100, 100, 255, 100);
}

