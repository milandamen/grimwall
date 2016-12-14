#ifndef FIFE_FACADE_H
#define FIFE_FACADE_H

#include "controller/engine.h"
#include "controller/enginesettings.h"
#include "model/model.h"
#include "model/structures/instance.h"
#include "view/visual.h"
#include "loaders/native/map/maploader.h"
#include "model/structures/map.h"
#include "model/structures/layer.h"
#include "view/camera.h"
#include "util/time/timemanager.h"
#include "eventchannel/eventmanager.h"
#include "gui/fifechan/fifechanmanager.h"
#include "util/log/logger.h"
#include "boost/filesystem.hpp"

#include "SDL.h"
#include "FIFEChan.h"
#include "FIFEKeyListener.h"
#include "Camera/FIFECamera.h"

#include "../IEngineFacade.h"
#include "FIFEMouseListener.h"
#include "FIFEKeyListener.h"
#include "../IGame.h"
#include "../../Input/ICallback.h"
#include "GUI/FIFEChanGuiManager.h"


class FIFEChanGuiManager;

namespace fs = boost::filesystem;

class FIFEFacade : public IEngineFacade {
private:
    FIFE::Engine* engine {nullptr};
    FIFE::Map* map {nullptr};

    FIFEChan* fifeChan {nullptr};
    FIFEChanGuiManager* guimanager {nullptr};
    FIFECamera* fifeCamera {nullptr};

    IGame* game {nullptr};
    FIFEKeyListener* keyListener {nullptr};

    FIFEMouseListener* mouseListener {nullptr};

    bool pumpingInitialized {false};
    
    void initView();
    void initInput();
public:
    FIFEFacade(IGame* game);
    ~FIFEFacade();

    /**** Settings ****/
    /**
     * Set the render backend used by the engine (OpenGL or SDL).
     */
    void setRenderBackend(std::string engine) override;

    /**
     * Gets the width of the window
     * @return Integer The window width
     */
    int getScreenWidth() override;

    /**
     * Sets the width of the window.
     */
    void setScreenWidth(int width) override;

    /**
     * Gets the width of the window
     * @return Integer The window width
     */
    int getScreenHeight() override;

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
    
    /**
     * Set a limit to the FPS
     */
    void setFPSLimit(int fpsLimit) override;


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


    /**** GUIManager ****/

    /**
     * Method to create a GUI manager
     * @return Pointer to instance of AGUIManager
     */
    AGUIManager* createGUIManager() override;

    /**
     * Method to set the active GUI manager
     * @param manager Pointer to AGUIManager instance
     */
    void setActiveGUIManager(AGUIManager* manager) override;

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
     *  load towers from map
     */
    std::vector<std::string> loadTowers() override;


    /**
     * Move the character
     */
    void move(std::string name, double x, double y, int moveSpeed) override;
  
    /**
     * Register a callback with a key combination
     */
    void registerCallback(std::string keys, ICallback* callback) override;

    /**
     * Zoom in
     */
    void zoomIn() override;

    /**
     * Zoom out
     */
    void zoomOut() override;

    /**
     * Update location
     */
    void updateLocation(int x, int y) override;

    /**
     * Creates a new instance on a given location and returns the name of the object
     */
    std::string createInstance(std::string objectName, std::string instanceName, double x, double y) override;

    /**
     * Gets the instance from the layer, then both removes and deletes it.
     */
    void deleteInstance(std::string instanceName) override;

    /**
     * Gets the instance from the layer, then removes it. Beware: this method does not delete the object.
     */
    void removeInstance(std::string instanceName) override;
    
    /**
     * Run a tick for userland code like input callbacks
     */
    void tick() override;

};

#endif
