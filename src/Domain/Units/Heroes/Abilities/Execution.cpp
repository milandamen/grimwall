

#include "Execution.h"
#include "../../../EngineFacade.h"

Execution::Execution(UnitManager<AHero> *hero, std::vector<UnitManager<ATower> *> *towers)
        : AAbility("Rage", 40), hero{hero}, towers{towers}
{}

int Execution::execute() {

    double x = hero->getX();
    double y = hero->getY();
    double reach = hero->getReach();
    int power = hero->getPower();

    UnitManager<ATower> *tower;
    for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end();) {
        tower = *it;

        double xDiff = std::abs(tower->getX() - x);
        double yDiff = std::abs(tower->getY() - y);

        if (xDiff < reach && yDiff < reach) {
            if (tower->getHitPoints() <= 500) {
                tower->receiveDamage(500);
            }
            else {
                tower->receiveDamage(power * 2);
            }

        }
        ++it;
    }

    return 1;
}