
#include "Game.h"
#include "EngineFacade.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    
    EngineFacade::engine()->init();
    initInput();
    EngineFacade::engine()->loadMap("assets/maps/level1_remake_conv.xml");
    
    // Game loop
    int lastTime = 0;
    int curTime = 0;

    while (running)
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

            //zoom in and out
            //EngineFacade::engine()->zoomIn();
            //EngineFacade::engine()->zoomOut();
            //EngineFacade::engine()->updateLocation(+1, -1);
        }
        
        // Render a frame
        EngineFacade::engine()->render();
        
        curTime = EngineFacade::engine()->getTime();
    }
    
    EngineFacade::destroy();     // TODO Currently crashes (SEGFAULT), problem not in my code.
    delete keyboardMapper;
}

void Game::quit()
{
    running = false;
}

void Game::initInput()
{
    keyboardMapper = new KeyboardMapper(this);
}
