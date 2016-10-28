
#include "AUnit.h"

AUnit::AUnit(std::string name, int range, int attackDelay, int power, int hitPoints)
        : name{name}, range{range}, attackDelay{attackDelay}, power{power}, hitPoints{hitPoints}
{

}

AUnit::~AUnit() {

}

std::string AUnit::getName() {
    return this->name;
}

int AUnit::getRange() {
    return this->range;
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

bool AUnit::isAlive() {
    return this->is_alive;
}

void AUnit::attack(AUnit* unit) {
    unit->inflictDamage(this->power);
}

void AUnit::inflictDamage(int hitPoints) {
    // Decrease hitpoints
    this->hitPoints -= hitPoints;

    // If hitPoints below 0, this unit is dead
    if(this->hitPoints < 0)
        this->is_alive = false;
}