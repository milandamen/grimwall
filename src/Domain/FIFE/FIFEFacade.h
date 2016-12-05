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
#include <gui/fifechan/fifechanmanager.h>

#include "boost/filesystem.hpp"
#include "SDL.h"

#include "../IEngineFacade.h"
#include "FIFEKeyListener.h"
#include "../IGame.h"
#include "../../Input/ICallback.h"
#include "Camera/FIFECamera.h"

// TODO Remove unnecesary
namespace FIFE
{
    class Engine;
    class EngineSettings;
    class Map;
    class Camera;
    class Instance;
    class IGUIManager;
}

namespace fs = boost::filesystem;

class FIFEFacade : public IEngineFacade, fcn::ActionListener, fcn::KeyListener, fcn::MouseListener {
private:
    FIFE::Engine* engine {nullptr};
    FIFE::FifechanManager* guimanager {nullptr};
    FIFE::Map* map {nullptr};
    FIFE::Camera* mainCamera {nullptr};

    fcn::Button* btnOptions {nullptr};
    fcn::Button* btnExit {nullptr};
    FIFECamera* fifeCamera {nullptr};
    
    IGame* game {nullptr};
    FIFEKeyListener* keyListener {nullptr};
    
    bool pumpingInitialized {false};
    
    void initView();
    void initInput();
public:
    FIFEFacade(IGame* game);
    ~FIFEFacade();

    /**** Encapsulation ****/

    /**
     * Get the GUI Manager
     * @return
     */
    FIFE::FifechanManager* getGuiManager() override;
    void action(const fcn::ActionEvent& actionEvent) override;
    void keyPressed(fcn::KeyEvent& keyEvent) override;
    void mousePressed(fcn::MouseEvent& mouseEvent) override;

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
     * Get layer by name
     */
    void setInstanceLocation(std::string name, double x, double y) override;
    
    /**
     * Register a callback with a key combination
     */
    void registerCallback(std::string, ICallback* callback) override;

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
    void updateLocation(std::string location) override;

    /**
     * Creates a new instance on a given location and returns the name of the object
     */
    std::string createInstance(std::string objectName, std::string instanceName, double x, double y) override;
};

#endif