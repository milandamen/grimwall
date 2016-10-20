
#include "../IEngineFacade.h"

#include "fife/core/controller/engine.h"
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

// TODO Remove unnecesary
namespace FIFE
{
    class Engine;
    class EngineSettings;
    class Map;
    class Camera;
    class Instance;
}

class FIFEFacade : public IEngineFacade {
private:
    FIFE::Engine* engine;
public:
    FIFEFacade();
    ~FIFEFacade();
    
    /** Settings **/
    
    void setRenderBackend(std::string engine) override;
    void setScreenWidth(int width) override;
    void setScreenHeight(int height) override;
    void setFullScreen(bool fullScreen) override;
    void setWindowTitle(std::string title) override;
    
    /** Initializing **/
    
    /**
     * Applies settings to engine and initializes it.
     */
    void init() override;
    
    /** Map **/
    
    /**
     * Load a map specified by the path into the engine.
     */
    void loadMap(std::string path) override;
    
    /** Running **/
    
    /**
     * Method to render current frame. To be run every game tick.
     */
    void render() override;
};