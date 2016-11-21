
#include "AUnit.h"

AUnit::AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints, int speed,
             int visibility, BuffDecorator *decorator)
        : name{name}, reach{reach}, attackDelay{attackDelay}, power{power}, hitPoints{hitPoints}, speed{speed}, visibility{visibility}, buffDecorator{decorator}
{

}

AUnit::~AUnit() {

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

int AUnit::getSpeed() {
    return this->speed;
}

int AUnit::getVisibility() {
    return this->visibility;
}

void AUnit::doDamage(int power) {
    // do damage
}