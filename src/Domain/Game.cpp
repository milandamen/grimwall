#include "Game.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    EngineFacade::engine()->setFPSLimit(60);
    
    EngineFacade::engine()->init();

    initInput();
    EngineFacade::engine()->loadMap("assets/maps/level1_remake_conv.xml");
    loadTowers();

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
    this->deleteTowers();
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

void Game::loadTowers()
{
    std::vector<std::string> towerIds = EngineFacade::engine()->loadTowers();

    for (unsigned int i = 0; i < towerIds.size(); ++i)
    {
        ATower* tower = new DefaultTower();
        tower->setId(towerIds.at(i));

        this->towers.push_back(tower);
    }
}

void Game::deleteTowers()
{
    for (unsigned int i = 0; i < this->towers.size(); ++i)
    {
        delete this->towers.at(i);
    }
    this->towers.clear();
}
