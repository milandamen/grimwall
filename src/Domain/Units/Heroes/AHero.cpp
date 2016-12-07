
#include "AHero.h"

AHero::AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility)
        : AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility)
{

}

AHero::~AHero() {
    for (std::vector<AAbility*>::iterator it = this->abilities.begin() ; it != this->abilities.end(); ++it)
        delete (*it);

    this->abilities.clear();
}

std::string AHero::getWeapon() {
    return this->weapon;
}

void AHero::executeAbility(int number) {
    this->abilities[number]->execute();
}

void AHero::addAbility(AAbility *ability) {
    this->abilities.push_back(ability);
}


void AHero::doDamage(int power) {
    //do the attack
}






