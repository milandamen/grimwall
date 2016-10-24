
#include "AHero.h"

AHero::AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints)
        : AUnit(name, reach, attackDelay, power, hitPoints), moveSpeed{moveSpeed}
{

}

std::string AHero::getWeapon() {
    return this->weapon;
}

int AHero::getMoveSpeed() {
    return this->moveSpeed;
}

void AHero::doDamage(int power) {
    //do the attack
}






