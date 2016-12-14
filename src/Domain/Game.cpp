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
    
    EngineFacade::destroy();
    delete keyboardMapper;
}

Game::~Game() {
    delete this->hero;
    this->deleteTowers();
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

    this->towers = generateTowers(towerIds);
}

void Game::deleteTowers()
{
    for (unsigned int i = 0; i < this->towers.size(); ++i)
    {
        delete this->towers.at(i);
    }
    this->towers.clear();
}

std::vector<UnitManager<ATower> *> Game::getTowers() {
    return this->towers;
}

void Game::letTowersAttack() {
    //iterate through all towers
    for(unsigned int i = 0; i < towers.size(); ++i)
    {
        // for each tower check there's an oposing unit within range

        UnitManager<ATower>* tower = towers.at(i);

        //check if attack delay has passed
        int timeSince = curTime - tower->getBase()->getTimeLastAttack();

        if(tower->getBase()->getTimeLastAttack() == -23 || timeSince >= tower->getAttackDelay())
        {
            //time delay passed

            //if unit is in range, check if it is the closest
            int unitX = hero->getX();
            int unitY = hero->getY();
            //calculate distance between unit and tower
            double deltaX = std::pow((unitX + tower->getX()) , 2.0);
            double deltaY = std::pow((unitY + tower->getY()) , 2.0);
            double distance = std::sqrt(deltaX + deltaY);

            if(distance <= tower->getReach())
            {
                //unit is in range, attack


                //get tower attack
                //subtract it from unit hp

                //update time tower last attacked
                tower->getBase()->setTimeLastAttack(curTime);

            }
        }



        //when closest unit is found attack it

    }
}

