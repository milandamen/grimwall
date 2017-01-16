
#include "AUnit.h"

AUnit::AUnit(std::string name, double reach, int attackDelay, int power, int hitPoints, double speed,
             int visibility)
        : name{name}, reach{reach}, power{power}, hitPoints{hitPoints}, speed{speed}, visibility{visibility}
{
    //convert time in ms to nr of ticks @ 60fps
    this->attackDelay = ((attackDelay/1000)*60);
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
    if (this->invincible) { return; }
    
    this->hitPoints -= power;
    this->updateStatsListener();
}

void AUnit::setInvincible(bool invincible)
{
    this->invincible = invincible;
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
    if (this->attackWait > 0)
        this->attackWait--;
}

bool AUnit::attack() {
    if (this->attackWait <= 0) {
        this->attackWait = this->attackDelay;
        return true;
    }
    
    return false;
}

void AUnit::setStatsListener(std::function<void()> delegate) {
    this->updateStatsListener = delegate;
}

bool AUnit::canAttack() {
    return this->attackWait <= 0;
}
