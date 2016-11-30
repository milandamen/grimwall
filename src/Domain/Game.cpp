
#include "Game.h"
#include "EngineFacade.h"
#include "Units/Heroes/Dralas.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    
    EngineFacade::engine()->init();

    initInput();
    EngineFacade::engine()->loadMap("assets/maps/level1_remake_conv.xml");
    loadTowers();

    this->hero = new Dralas();

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
        }
        
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

AHero* Game::getHero() {
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

void Game::loadTowers()
{
    std::vector<std::string> towerIds = EngineFacade::engine()->loadTowers();

    for (unsigned int i = 0; i < towerIds.size(); ++i)
    {
        ATower* tower = new DefaultTower();
        tower->setId(towerIds.at(i));

        this->towers.push_back(tower);
    }

    std::cout << "Nr of towers:  "<< this->towers.size() << std::endl;
    for (unsigned int i = 0; i < towerIds.size(); ++i)
    {
        std::cout << this->towers.at(i)->getId() << std::endl;
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
