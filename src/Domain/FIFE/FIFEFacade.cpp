 
#include "FIFEFacade.h"

FIFEFacade::FIFEFacade(IGame* game)
{
    this->game = game;
    engine = new FIFE::Engine();
    fs::path defaultFontPath("assets/fonts/FreeSans.ttf");
    FIFE::EngineSettings& settings = engine->getSettings();
    settings.setBitsPerPixel(0);
    settings.setInitialVolume(5.0);
    settings.setWindowTitle("Grimwall v0.1");
    settings.setDefaultFontGlyphs("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&amp;`'*#=[]\"");
    settings.setDefaultFontPath(defaultFontPath.string());
}

FIFEFacade::~FIFEFacade()
{
    delete keyListener;
    delete fifeCamera;

//     delete mainCamera;
//     delete map;
//     delete engine;
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
    initInput();
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

void FIFEFacade::setInstanceLocation(std::string name, int x, int y) {
    if (map) {
        std::cout << "map, ";
        FIFE::Layer *layer = map->getLayer("unitLayer");

        if (layer) {
            std::cout << "layer, ";
            FIFE::Instance *instance = layer->getInstance(name);

            if (instance) {
                std::cout << "instance, ";

                // Get the current location of the instance
                FIFE::Location destination(instance->getLocation());

                FIFE::ScreenPoint screenPoint(x, y);
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


