#ifndef IENGINEFACADE_H
#define IENGINEFACADE_H

#include <iostream>

#include <gui/guimanager.h>
#include <util/structures/rect.h>
#include <vector>
#include "eventchannel/mouse/ec_mouseevent.h"
#include "../Input/ICallback.h"
#include "../GUI/AGUIManager.h"


#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"

/**
 * Class to be extended by classes like FIFEFacade
 */
class IEngineFacade
{
public:
    virtual ~IEngineFacade() {};

    /** Settings **/
    
    virtual void setRenderBackend(std::string engine) = 0;
    virtual const uint16_t getScreenWidth() = 0;
    virtual void setScreenWidth(int width) = 0;
    virtual const uint16_t getScreenHeight() = 0;
    virtual void setScreenHeight(int height) = 0;
    virtual void setFullScreen(bool fullScreen) = 0;
    virtual void setWindowTitle(std::string title) = 0;
    virtual void setFPSLimit(int fpsLimit) = 0;
    
    /** Initializing **/
    
    /**
     * Applies settings to engine and initializes it.
     */
    virtual void init() = 0;
    
    /** Map **/
    
    /**
     * Load a map specified by the path into the engine.
     */
    virtual void loadMap(std::string path) = 0;

    /** GUIManager **/

    /**
     * Method to create a GUI manager
     * @return Pointer to instance of AGUIManager
     */
    virtual AGUIManager* createGUIManager() = 0;

    /**
     * Method to set the active GUI manager
     * @param manager Pointer to AGUIManager instance
     */
    virtual void setActiveGUIManager(AGUIManager* manager) = 0;

    /** Running **/
    
    /**
     * Method to render current frame. To be run every game tick.
     */
    virtual void render() = 0;
    
    /**
     * Get the amount of frames per second
     */
    virtual int getFPS() = 0;
    
    /**
     * Get the current time in milliseconds
     */
    virtual int getTime() = 0;

    /**
     * Register a callback with a key combination
     */
    virtual void registerCallback(std::string keys, ICallback* callback) = 0;

    //TODO: register Callback for mouse listener
    /**
     * Zoom in
     */
    virtual void zoomIn() = 0;

    /**
     * Zoom out
     */
    virtual void zoomOut() = 0;

    /**
     * Update the screen camera
     */
    virtual void updateLocation(int x, int y) = 0;

    /**
     * Creates a new instance on a given location and returns the name of the object
     */
    virtual std::string createInstance(std::string objectName, std::string instanceName, double x, double y) = 0;

    /**
    * Gets the instance from the layer, then both removes and deletes it.
    */
    virtual void deleteInstance(std::string instanceName, std::string layerName = "unitLayer") = 0;

    /**
     * Gets the instance from the layer, then removes it. Beware: this method does not delete the object.
     */
    virtual void removeInstance(std::string instanceName, std::string layerName = "unitLayer") = 0;

    virtual void setInstanceAction(std::string name, std::string action, std::string layerName = "unitLayer") = 0;
    virtual bool instanceExists(std::string name, std::string layerName = "unitLayer") = 0;
    virtual double getInstanceX(std::string name, std::string layerName = "unitLayer") = 0;
    virtual double getInstanceY(std::string name, std::string layerName = "unitLayer") = 0;

    /**
     * Set the location of an instance
     */
    virtual void move(std::string name, std::string layerName, double x, double y, int moveSpeed) = 0;
    
    /**
     * Run a tick for userland code like input callbacks
     */
    virtual void tick() = 0;
    
    /**
     *  load towers from map
     */
    virtual std::vector<UnitManager<ATower>*> loadTowers() = 0;

    /**
     * Play music
     */
    virtual void playMusic(std::string asset) = 0;

    /*
     * Play sound effect
     */
    virtual void playSoundEffect(std::string asset) = 0;

    /*
     * Stop playing music
     */
    virtual void stopMusic() = 0;

    /*
     * Stop playing sound effect
     */
    virtual void stopSoundEffect() = 0;

    /*
     * Stop playing music&soundEffect
     */
    virtual void stopAllMusic() = 0;

};

#endif