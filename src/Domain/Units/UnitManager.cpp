

#include "UnitManager.h"

UnitManager::UnitManager(IUnit *unit)
    : unit{unit}
{}

UnitManager::~UnitManager() {
    delete this->unit;
}

std::string UnitManager::getName() {
    return unit->getName();
}

int UnitManager::getReach() {
    return unit->getReach();
}

int UnitManager::getAttackDelay() {
    return unit->getAttackDelay();
}

int UnitManager::getPower() {
    return unit->getPower();
}

int UnitManager::getHitPoints() {
    return unit->getHitPoints();
}

int UnitManager::getSpeed() {
    return unit->getSpeed();
}

int UnitManager::getVisibility() {
    return unit->getVisibility();
}

void UnitManager::doDamage(int power) {
    unit->doDamage(power);
}

double UnitManager::getX() {
    return unit->getX();
}

void UnitManager::setX(double x) {
    unit->setX(x);
}

double UnitManager::getY() {
    return unit->getY();
}

void UnitManager::setY(double y) {
    unit->setY(y);
}
