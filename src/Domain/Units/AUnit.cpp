
#include "AUnit.h"

std::string AUnit::getName() {
    return this->name;
}

int AUnit::getReach() {
    return this->reach;
}

int AUnit::getAttackDelay() {
    return this->attackDelay;
}

int AUnit::getPower() {
    return this->power;
}

int AUnit::getHitPoints() {
    return this->hitPoints;
}

void AUnit::doDamage(int power) {
    // do damage
}