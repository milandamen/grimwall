#include "TowerManager.h"


TowerManager::TowerManager()
{}

void TowerManager::tick() {
    //called once every cycle

    for(unsigned int i = 0; i < towers->size(); ++i)
    {
        // for each tower check if the hero or troup is within range
        UnitManager<ATower>* tower {towers->at(i)};

//         //check if attack delay has passed
//         int timeSince {curTime - tower->getBase()->getTimeLastAttack()};
// 
//         if(tower->getBase()->getTimeLastAttack() == 0 || timeSince >= tower->getAttackDelay()
//             || (this->speedHackEnabled && timeSince*3 >= tower->getAttackDelay()))

        UnitManager<ATroup>* unit {nullptr};
        std::vector<UnitManager<ATroup> *>::iterator itUnit {nullptr};
        bool heroIsTarget {false};
        tower->tick();
        //check if tower can attack
        bool canAttack {tower->canAttack()};
        if(canAttack || (this->speedHackEnabled && ++this->speedHackLastTick % 3 == 0))
        {
            //time delay passed
            updateLocation(tower, tower->getName());

            //determine closest target
            double rangeCurrentTarget {100}; //set to value greater than any towers range
            unsigned int t = 0;
            for(auto it = friendlyUnits->begin(); it != friendlyUnits->end(); ++it)
            {
                //calculate distance between unit and tower

                double unitX {this->friendlyUnits->at(t)->getX()};
                double unitY {this->friendlyUnits->at(t)->getY()};

                double deltaX {std::pow((unitX - tower->getX()), 2.0)};
                double deltaY {std::pow((unitY - tower->getY()), 2.0)};

                double distance {std::sqrt(deltaX + deltaY)};

                if(distance <= tower->getReach())
                {
                    //unit in range, check if it is the closest
                    if(distance < rangeCurrentTarget)
                    {
                        //current unit is closer, set as target

                        rangeCurrentTarget = distance;
                        unit = friendlyUnits->at(t);
                        itUnit = it;

                    }
                }
                ++t;
            }
            //check hero viability as target
            double unitX {this->hero->getX()};
            double unitY {this->hero->getY()};

            double deltaX {std::pow((unitX - tower->getX()), 2.0)};
            double deltaY {std::pow((unitY - tower->getY()), 2.0)};

            double distance {std::sqrt(deltaX + deltaY)};

            if(distance <= tower->getReach() && distance < rangeCurrentTarget)
            {
                //hero is the target
                heroIsTarget = true;
            }

             // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(0, 100);
            int chance {distr(eng)};
            if(heroIsTarget)
            {
                //check visibility
                if(chance < hero->getVisibility())
                {
                    tower->attack();
                    this->hero->receiveDamage(tower->getPower());

                    std::cout << "Hero hp: " << this->hero->getHitPoints() << std::endl;
                    std::cout << "Hero mana: " << this->hero->getBase()->getMana() << std::endl;
                    EngineFacade::engine()->setInstanceAction(tower->getBase()->getId(),"attack", "towerLayer");
                    EngineFacade::engine()->playSoundEffect("defaultTowerShot");
                } else
                    EngineFacade::engine()->setInstanceAction(tower->getBase()->getId(),"stand", "towerLayer");

            }
            else if(unit)
            {
                if(chance < unit->getVisibility())
                {
                    //check visibility
                    tower->attack();
                    //get tower attack
                    //subtract it from unit hp
                    unit->receiveDamage(tower->getPower());

                    std::cout << "Unit hp: " << unit->getHitPoints() << std::endl;
                    EngineFacade::engine()->setInstanceAction(tower->getBase()->getId(),"attack", "towerLayer");
                    EngineFacade::engine()->playSoundEffect("defaultTowerShot");

                } else
                    EngineFacade::engine()->setInstanceAction(tower->getBase()->getId(),"stand", "towerLayer");
            }
        }
    }
}

void TowerManager::setUnits(std::vector<UnitManager<ATroup> *>* friendlyUnits)
{
    this->friendlyUnits = friendlyUnits;
}

void TowerManager::setTowers(std::vector<UnitManager<ATower> *>* towers)
{
    this->towers = towers;
}

void TowerManager::setHero(UnitManager<AHero>* hero)
{
    this->hero = hero;
}

void TowerManager::setSpeedHack(bool enabled)
{
    this->speedHackEnabled = enabled;
}
