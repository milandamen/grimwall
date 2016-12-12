
#include "ATower.h"

ATower::ATower(std::string name, int reach, int attackDelay, int power, int hitPoints, int visibility)
        : AUnit(name, reach, attackDelay, 0, power, hitPoints, visibility)
{}

std::string ATower::getId() {
    return this->id;
}

void ATower::setId(std::string id) {
    this->id = id;
}

