
#include "AUnit.h"

AUnit::AUnit(std::string name, double reach, int attackDelay, int power, int hitPoints, double speed,
             int visibility)
        : name{name}, reach{reach}, attackDelay{attackDelay}, power{power}, hitPoints{hitPoints}, speed{speed}, visibility{visibility}
{
}

AUnit::~AUnit() {

}

std::string AUnit::getName() {
    return this->name;
}

double AUnit::getReach() {
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

double AUnit::getSpeed() {
    return this->speed;
}

int AUnit::getVisibility() {
    return this->visibility;
}

void AUnit::receiveDamage(int power) {
    this->hitPoints -= power;
}

double AUnit::getX() {
    return this->x;
}

void AUnit::setX(double x) {
    this->x = x;
}

double AUnit::getY() {
    return this->y;
}

void AUnit::setY(double y) {
    this->y = y;
}

void AUnit::setNext(IUnit *next) {}

void AUnit::setPrevious(IUnit *previous) {
    this->previous = previous;
}

void AUnit::tick() {

}

void AUnit::setTimeLastAttack(int time) {
    this->timeLastAttack = time;
}

int AUnit::getTimeLastAttack() {
    return this->timeLastAttack;
}

void AUnit::setStatsListener(std::function<void()> delegate) {
    this->updateStatsListener = delegate;
}