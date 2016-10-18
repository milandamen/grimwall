#include <iostream>
#include "Domain/Game.h"

// 3rd party includes, this will be moved to FIFE facade later
#include "fife/core/controller/engine.h"

namespace FIFE
{
	class Engine;
	class EngineSettings;
	class Map;
	class Camera;
	class Instance;
}

int main() {
    std::cout << "test" << std::endl; 
    
    // Testing if FIFE can be included
    // This will be moved to the FIFE facade later
    FIFE::Engine* m_engine = new FIFE::Engine();
    delete m_engine;
    
    return 0;
}