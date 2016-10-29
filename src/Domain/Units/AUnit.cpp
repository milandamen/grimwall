
#include "AUnit.h"
#include "IUnit.h"

AUnit::AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints)
        : name{name}, reach{reach}, attackDelay{attackDelay}, power{power}, hitPoints{hitPoints}, originalHitPoints{hitPoints}
{

}

AUnit::~AUnit(){

}

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

int AUnit::getOriginalHitPoints() {
    return this->originalHitPoints;
}

void AUnit::doDamage(int power) {
    // do damage
}