#include <tgmath.h>
#include "TowerManager.h"
#include "UnitFactory.h"

TowerManager::TowerManager()
{}

void TowerManager::tick(int curTime) {

    //called once every cycle


    for(unsigned int i = 0; i < towers->size(); ++i)
    {
        // for each tower check if the hero is within range

        UnitManager<ATower>* tower {towers->at(i)};
        UnitManager<AUnit>* unit {nullptr};
        bool heroIsTarget {nullptr};

        //check if attack delay has passed
        int timeSince {curTime - tower->getBase()->getTimeLastAttack()};

        if(tower->getBase()->getTimeLastAttack() == 0 || timeSince >= tower->getAttackDelay())
        {
            //time delay passed
            updateLocation(tower, tower->getName());

            //determine closest target
            double rangeCurrentTarget {100}; //set to value greater than any towers range
            for(unsigned int t = 0; t <= friendlyUnits.size(); ++t)
            {
                //calculate distance between unit and tower


                double unitX;
                double unitY;

                if(t == friendlyUnits.size())
                {
                    //checked all units, now check the hero
                    unitX = this->hero->getX();
                    unitY = this->hero->getY();


                }
                else
                {
                    unitX = this->friendlyUnits.at(t)->getX();
                    unitY = this->friendlyUnits.at(t)->getY();
                }
                double deltaX {std::pow((unitX - tower->getX()), 2.0)};
                double deltaY {std::pow((unitY - tower->getY()), 2.0)};

                double distance {std::sqrt(deltaX + deltaY)};

                if(distance <= tower->getReach())
                {
                    //unit in range, check if it is the closest
                    if(distance < rangeCurrentTarget)
                    {
                        //current unit is closer, set as target
                        if(t == friendlyUnits.size())
                        {
                            //hero is the target
                            heroIsTarget = true;
                        }
                        else
                        {
                            rangeCurrentTarget = distance;
                            unit = friendlyUnits.at(t);
                        }

                    }
                }
            }

            //determine if hero is the closest target





            //check if target was found
            if(heroIsTarget)
            {
                this->hero->receiveDamage(tower->getPower());

                std::cout << "Unit hp: " << this->hero->getHitPoints() << std::endl;
                //update time tower last attacked
                tower->getBase()->setTimeLastAttack(curTime);
            }
            else if(unit)
            {
                //get tower attack
                //subtract it from unit hp
                unit->receiveDamage(tower->getPower());

                std::cout << "Unit hp: " << unit->getHitPoints() << std::endl;
                //update time tower last attacked
                tower->getBase()->setTimeLastAttack(curTime);
            }

        }
    }
}

void TowerManager::setUnits(std::vector<UnitManager<AUnit> *> friendlyUnits)
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


