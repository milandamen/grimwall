
#include "../IEngineFacade.h"

#include "fife/core/controller/engine.h"
#include "fife/core/controller/enginesettings.h"
#include "fife/core/loaders/native/map/maploader.h"
#include "model/structures/map.h"
#include "model/structures/layer.h"
#include "fife/core/view/camera.h"
#include "util/time/timemanager.h"

#include "boost/filesystem.hpp"
#include "SDL.h"

namespace fs = boost::filesystem;

class FIFEFacade : public IEngineFacade {
private:
    FIFE::Engine* engine {nullptr};
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};

    double zoomIncrement;
    double maxZoom;
    double minZoom;
    
    bool pumpingInitialized {false};
    
    void initView();
public:
    FIFEFacade();
    ~FIFEFacade();
    
    
    /**** Settings ****/
    
    /**
     * Set the render backend used by the engine (OpenGL or SDL).
     */
    void setRenderBackend(std::string engine) override;
    
    /**
     * Sets the width of the window.
     */
    void setScreenWidth(int width) override;
    
    /**
     * Sets the height of the window.
     */
    void setScreenHeight(int height) override;
    
    /**
     * Sets fullscreen mode on window.
     */
    void setFullScreen(bool fullScreen) override;
    
    /**
     * Sets windows title.
     */
    void setWindowTitle(std::string title) override;
    
    
    /**** Initializing ****/
    
    /**
     * Applies settings to engine and initializes it.
     */
    void init() override;
    
    /** Map **/
    
    /**
     * Load a map specified by the path into the engine.
     */
    void loadMap(std::string path) override;
    
    
    /**** Running ****/
    
    /**
     * Method to render current frame. To be run every game tick.
     */
    void render() override;
    
    /**
     * Get the amount of frames per second
     */
    int getFPS() override;
    
    /**
     * Get the current time in milliseconds
     */
    int getTime() override;

    /**
     * Zoom in
     */
    void zoomIn() override;

    /**
     * Zoom out
     */
    void zoomOut() override;
};
