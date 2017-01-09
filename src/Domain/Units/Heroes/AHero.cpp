
#include "AHero.h"

AHero::AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility)
        : AUnit(name, reach, attackDelay, power, hitPoints, moveSpeed, visibility)
{

}

AHero::~AHero() {
    for (auto& ability : this->abilities) {
        delete ability;
    }

    this->abilities.clear();
}

std::string AHero::getWeapon() {
    return this->weapon;
}

void AHero::executeAbility(unsigned int number) {
    if (number < this->abilities.size() && number >= 0) {
        this->abilities[number]->execute();
    }
}

void AHero::addAbility(AAbility *ability) {
    this->abilities.push_back(ability);
}
