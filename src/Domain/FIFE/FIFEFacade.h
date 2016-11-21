#ifndef FIFE_FACADE_H
#define FIFE_FACADE_H

#include "controller/engine.h"
#include "controller/enginesettings.h"
#include "loaders/native/map/maploader.h"
#include "model/structures/map.h"
#include "model/structures/layer.h"
#include "view/camera.h"
#include "util/time/timemanager.h"
#include "eventchannel/eventmanager.h"

#include "boost/filesystem.hpp"
#include "SDL.h"

#include "../IEngineFacade.h"
#include "FIFEKeyListener.h"
#include "../Game.h"
#include "../../Input/ICallback.h"

class Game;
class FIFEKeyListener;

namespace fs = boost::filesystem;

class FIFEFacade : public IEngineFacade {
private:
    FIFE::Engine* engine {nullptr};
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};
    
    Game* game {nullptr};
    FIFEKeyListener* keyListener {nullptr};
    
    bool pumpingInitialized {false};
    
    void initView();
    void initInput();
public:
    FIFEFacade(Game* game);
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
     * Register a callback with a key combination
     */
    void registerCallback(std::string, ICallback* callback) override;
};

#endif