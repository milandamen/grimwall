
#include "../IEngineFacade.h"

#include "fife/core/controller/engine.h"

namespace FIFE
{
    class Engine;
    class EngineSettings;
    class Map;
    class Camera;
    class Instance;
}

class FIFEFacade : public IEngineFacade {
public:
    FIFEFacade();
    ~FIFEFacade();
    
    // Initializing
    
    void setRenderBackend(std::string engine);
    void setScreenWidth(int width);
    void setScreenHeight(int height);
    void setFullScreen(bool fullScreen);
    void setWindowTitle(std::string title);
    
    // Map
    
    /**
     * Load a map specified by the path into the engine.
     */
    void loadMap(std::string path);
    
    // Running
    
    /**
     * Method to render current frame. To be run every game tick.
     */
    void render();
};