
#include "Game.h"
#include "EngineFacade.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE");
    EngineFacade::engine()->setRenderBackend("OpenGL");
    
    EngineFacade::engine()->init();
    EngineFacade::engine()->loadMap("assets/maps/shrine.xml");
    
    // Game loop
    int lastTime = 0;
    int curTime = 0;
    while (!quit)
    {
        // Update FPS reading approx. every second
        if ((curTime > 0) && (curTime - lastTime >= 1000))
        {
            // Create Title + FPS string
            std::ostringstream oss;
            oss << "Grimwall [FPS: " << EngineFacade::engine()->getFPS() << "]";
            
            // Show FPS in windows title
            EngineFacade::engine()->setWindowTitle(oss.str());
            
            // Update the last time FPS was calculated
            lastTime = EngineFacade::engine()->getTime();
        }
        
        // Render a frame
        EngineFacade::engine()->render();
        
        curTime = EngineFacade::engine()->getTime();
    }
    
//     EngineFacade::destroy();     // TODO Currently crashes (SEGFAULT), problem not in my code.
}
