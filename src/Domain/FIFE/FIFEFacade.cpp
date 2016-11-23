 
#include "FIFEFacade.h"

FIFEFacade::FIFEFacade()
{
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
    delete mainCamera;
    delete map;
    delete engine;
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
}

void FIFEFacade::loadMap(std::string path)
{
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
    if (map)
    {
        // get the main camera for this map
        mainCamera = map->getCamera("main");

        if (mainCamera)
        {
            // attach the controller to the camera
//             m_viewController->AttachCamera(mainCamera);
//             m_viewController->EnableCamera(true);
            mainCamera->setEnabled(true);

            // get the renderer associated with viewing objects on the map
            FIFE::RendererBase* renderer = mainCamera->getRenderer("InstanceRenderer");

            if (renderer)
            {
                // activate all layers associated with the renderer
                // for this map, this must be done to see anything
                renderer->activateAllLayers(map);
            }

//             // get the mini camera attached to the map
//             FIFE::Camera* miniCamera = map->getCamera("small");
// 
//             // default the small camera to off, we will revisit the
//             // mini camera in a later demo
//             if (miniCamera)
//             {
//                 miniCamera->setEnabled(false);
//             }
        }
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
            FIFE::Instance* instance = layer->getInstance(name);

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

