#include "Game.h"

#include "Units/Heroes/Abilities/DeathStrike.h"

Game::Game()
{
    EngineFacade::setEngine("FIFE", this);
    EngineFacade::engine()->setRenderBackend("OpenGL");
    EngineFacade::engine()->init();

    this->guirepo = new GUIRepo();
    this->guirepo->addGUI("MainMenu", new ScreenMainMenu(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("GameOver", new ScreenGameOver(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("Won", new ScreenWon(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("SelectHero", new ScreenSelectHero(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("SelectLevel", new ScreenSelectLevel(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("Options", new ScreenOptions(this, EngineFacade::engine()->createGUIManager()));
    this->guirepo->addGUI("Game", new ScreenGame(this, EngineFacade::engine()->createGUIManager()));

    EngineFacade::engine()->setActiveGUIManager(this->guirepo->getGUI("MainMenu")->getGuiManager());
    EngineFacade::engine()->setFPSLimit(60);
    EngineFacade::engine()->init();

    this->initInput();

    //this->hero = new UnitManager<AHero>(new Dralas());
    //this->hero->getBase()->addAbility(new DeathStrike(this->hero));
    
    // Game loop
    this->curTime = 0;
    this->lastTime = 0;
    this->paused = true;

    while (this->running)
    {
        updateFPS();

        // Check if we are in pause state
        if(!this->paused) {
            // Run an engine tick for userland code
            EngineFacade::engine()->tick();
        }

        // Render a frame
        EngineFacade::engine()->render();
        
        this->curTime = EngineFacade::engine()->getTime();
    }
    
    EngineFacade::destroy();
    delete this->keyboardMapper;
}

Game::~Game() {
    delete this->hero;
    this->deleteTowers();
}

void Game::setMap(std::string path)
{
    EngineFacade::engine()->loadMap(path);
    this->loadTowers();
}

int Game::getCurrentScore() {
    return this->score;
}

bool Game::isPaused()
{
    return this->paused;
}

void Game::setPaused(bool paused)
{
    this->paused = paused;
}

void Game::setHero(AHero *hero)
{
    if(this->hero != nullptr)
        delete this->hero;

    this->hero = new UnitManager<AHero>(hero);
}

void Game::setUI(std::string name)
{
    GUI* gui = this->guirepo->getGUI(name);
    if(gui != nullptr)
        EngineFacade::engine()->setActiveGUIManager(gui->getGuiManager());
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
