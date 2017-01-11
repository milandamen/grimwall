#include "Game.h"

#include "Units/Heroes/Abilities/DeathStrike.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");

    EngineFacade::engine()->setFPSLimit(60);

    EngineFacade::engine()->init();

    initInput();
    EngineFacade::engine()->loadMap("assets/maps/level1_remake_conv.xml");
    loadTowers();

    this->hero = new UnitManager<AHero>(new Dralas());
    this->hero->getBase()->addAbility(new DeathStrike(this->hero));
    
    setSaveGameManager(new SaveGameManager {"TEXT"});
    
    this->towerManager.setTowers(this->getTowers());
    this->towerManager.setHero(hero);

    // Game loop
    curTime = 0;
    lastTime = 0;

    while (running)
    {
        updateFPS();
        
        // Run an engine tick for userland code
        EngineFacade::engine()->tick();
        this->tick();

        // Render a frame
        EngineFacade::engine()->render();
        curTime = EngineFacade::engine()->getTime();
    }
    
    EngineFacade::destroy();
    delete keyboardMapper;
}

Game::~Game() {
    delete this->hero;
    this->deleteTowers();
}

void Game::tick() {
    updateLocation(this->hero, this->hero->getName());
    this->towerManager.tick(curTime);

    if (this->hero->getHitPoints() <= 0){
        this->lose();
    }
    else if (this->towers.size() <= 0){
        this->win();
    }

    this->hero->tick();
}

void Game::win() {
    std::cout << "win";
}

void Game::lose() {
    std::cout << "lose";
}

UnitManager<AHero>* Game::getHero() {
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
    this->towers = EngineFacade::engine()->loadTowers();
}

void Game::deleteTowers()
{
    for (unsigned int i = 0; i < this->towers.size(); ++i)
    {
        delete this->towers.at(i);
    }
    this->towers.clear();
}

std::vector<UnitManager<ATower> *>* Game::getTowers() {
    return &this->towers;
}

ISaveGameManager* Game::getSaveGameManager()
{
    return this->saveGameManager;
}

void Game::setSaveGameManager(ISaveGameManager* saveGameManager)
{
    this->saveGameManager = saveGameManager;
}

