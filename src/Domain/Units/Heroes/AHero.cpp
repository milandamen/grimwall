
#include "AHero.h"

AHero::AHero() {

}

AHero::AHero(std::string name, std::string weapon, int reach, int moveSpeed, int attackDelay, int power,
             int hitPoints): name{name}, weapon{weapon}, reach{reach}, moveSpeed{moveSpeed}, attackDelay{attackDelay}, power{power}, hitPoints{hitPoints} {

}

AHero::~AHero() {

}

std::string AHero::getName() {
    return this->name;
}

std::string AHero::getWeapon() {
    return this->weapon;
}

int AHero::getReach() {
    return this->reach;
}

int AHero::getMoveSpeed() {
    return this->moveSpeed;
}

int AHero::getAttackDelay() {
    return this->attackDelay;
}

int AHero::getPower() {
    return this->power;
}

int AHero::getHitPoints() {
    return this->hitPoints;
}





