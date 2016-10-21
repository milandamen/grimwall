#ifndef IENGINEFACADE_H
#define IENGINEFACADE_H

#include <iostream>

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
};

#endif