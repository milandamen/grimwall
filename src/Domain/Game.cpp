
#include "Game.h"
#include "EngineFacade.h"
#include "Units/Heroes/Dralas.h"
#include "Units/Buff/BoneStormBuff.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    EngineFacade::engine()->setFPSLimit(60);
    
    EngineFacade::engine()->init();
    initInput();
    EngineFacade::engine()->loadMap("assets/maps/level1_remake_conv.xml");

    this->hero = new UnitManager(new Dralas());

    // Game loop
    curTime = 0;
    lastTime = 0;

    while (running)
    {
        updateFPS();
        
        // Run an engine tick for userland code
        EngineFacade::engine()->tick();
        
        // Render a frame
        EngineFacade::engine()->render();
        
        curTime = EngineFacade::engine()->getTime();
    }
    
    EngineFacade::destroy();     // TODO Currently crashes (SEGFAULT), problem not in my code.
    delete keyboardMapper;
}

Game::~Game() {
    delete this->hero;
}

UnitManager* Game::getHero() {
    return this->hero;
}

void Game::quit()
{
    running = false;
}

void Game::initInput()
{
    keyboardMapper = new KeyboardMapper(this);
}

void Game::updateFPS()
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
}
