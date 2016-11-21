
#include "AHero.h"

AHero::AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility)
        : AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility, new BuffDecorator())
{

}

AHero::~AHero() {}

std::string AHero::getWeapon() {
    return this->weapon;
}


void AHero::doDamage(int power) {
    //do the attack
}






