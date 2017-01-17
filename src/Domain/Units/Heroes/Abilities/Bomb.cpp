#include "Bomb.h"
#include "../../../EngineFacade.h"

#include <cmath>

Bomb::Bomb(UnitManager<AHero>* hero, std::vector<UnitManager<ATower> *>* towers)
        : AAbility("Bomb", 50), hero{hero}, towers{towers}
{}

int Bomb::execute()
{
    double x = this->hero->getX();
    double y = this->hero->getY();

    UnitManager<ATower> *tower;
    for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end();) {
        tower = *it;

        double xDiff = std::abs(tower->getX() - x);
        double yDiff = std::abs(tower->getY() - y);

        if (xDiff < 2 && yDiff < 2) {
            tower->receiveDamage(750);
        }
        ++it;
    }
    return 1;
}