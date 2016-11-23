#ifndef IENGINEFACADE_H
#define IENGINEFACADE_H

#include <iostream>
#include <util/structures/rect.h>

#include "eventchannel/mouse/ec_mouseevent.h"
#include "../Input/ICallback.h"

/**
 * Class to be extended by classes like FIFEFacade
 */
class IEngineFacade
{
public:
    virtual ~IEngineFacade() {};
    
    /** Settings **/
    
    virtual void setRenderBackend(std::string engine) = 0;
    virtual void setScreenWidth(int width) = 0;
    virtual void setScreenHeight(int height) = 0;
    virtual void setFullScreen(bool fullScreen) = 0;
    virtual void setWindowTitle(std::string title) = 0;
    virtual void setInstanceLocation(std::string name, int x, int y) = 0;
    
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
    virtual void registerCallback(std::string, ICallback* callback) = 0;

    /**
     * Zoom in
     */
    virtual void zoomIn() = 0;

    /**
     * Zoom out
     */
    virtual void zoomOut() = 0;

    /**
     * update screen camera
     */
    virtual void updateLocation(std::string location) = 0;

};

#endif