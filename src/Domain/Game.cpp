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
        letTowersAttack();
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

void Game::letTowersAttack() {
    //iterate through all towers
    for(unsigned int i = 0; i < towers.size(); ++i)
    {
        // for each tower check if the hero is within range
        UnitManager<ATower>* tower {towers.at(i)};

        //check if attack delay has passed
        int timeSince {curTime - tower->getBase()->getTimeLastAttack()};

        if(tower->getBase()->getTimeLastAttack() == 0 || timeSince >= tower->getAttackDelay())
        {
            //time delay passed
            updateLocation(tower, tower->getName());
            updateLocation(this->hero, this->hero->getName());

            //calculate distance between unit and tower
            double deltaX {std::pow((hero->getX() - tower->getX()), 2.0)};
            double deltaY {std::pow((hero->getY() - tower->getY()), 2.0)};

            double distance {std::sqrt(deltaX + deltaY)};

            if(distance <= tower->getReach())
            {
                //hero in range, attack

                //get tower attack
                //subtract it from hero hp
                int damage {tower->getPower()};
                hero->receiveDamage(damage);

                std::cout << "Hero hp: " << hero->getHitPoints() << std::endl;
                //update time tower last attacked
                tower->getBase()->setTimeLastAttack(curTime);

            }
        }
    }
}

