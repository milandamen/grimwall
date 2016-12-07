

#ifndef GRIMWALL_UNITMANAGER_H
#define GRIMWALL_UNITMANAGER_H

#include <string>
#include "IUnit.h"
#include "Buff/BuffDecorator.h"

template <typename UnitType>
class UnitManager : public IUnit {
private:
    UnitType* base {nullptr};
    IUnit* unit {nullptr};
public:
    UnitManager(UnitType* unit);
    ~UnitManager();
    std::string getName() override;
    int getReach() override;
    int getAttackDelay() override;
    int getPower() override;
    int getHitPoints() override;
    int getSpeed() override;
    int getVisibility() override;
    void doDamage(int power) override;

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;

    UnitType* getBase();
    IUnit* getUnit();

    void buff(BuffDecorator* decorator);
};

template <typename UnitType>
UnitManager<UnitType>::UnitManager(UnitType *unit)
        : unit{unit}, base{unit}
{}

template <typename UnitType>
UnitManager<UnitType>::~UnitManager() {
    delete this->unit;
}

template <typename UnitType>
std::string UnitManager<UnitType>::getName() {
    return unit->getName();
}

template <typename UnitType>
int UnitManager<UnitType>::getReach() {
    return unit->getReach();
}

template <typename UnitType>
int UnitManager<UnitType>::getAttackDelay() {
    return unit->getAttackDelay();
}

template <typename UnitType>
int UnitManager<UnitType>::getPower() {
    return unit->getPower();
}

template <typename UnitType>
int UnitManager<UnitType>::getHitPoints() {
    return unit->getHitPoints();
}

template <typename UnitType>
int UnitManager<UnitType>::getSpeed() {
    return unit->getSpeed();
}

template <typename UnitType>
int UnitManager<UnitType>::getVisibility() {
    return unit->getVisibility();
}

template <typename UnitType>
void UnitManager<UnitType>::doDamage(int power) {
    unit->doDamage(power);
}

template <typename UnitType>
double UnitManager<UnitType>::getX() {
    return unit->getX();
}

template <typename UnitType>
void UnitManager<UnitType>::setX(double x) {
    unit->setX(x);
}

template <typename UnitType>
double UnitManager<UnitType>::getY() {
    return unit->getY();
}

template <typename UnitType>
void UnitManager<UnitType>::setY(double y) {
    unit->setY(y);
}

template <typename UnitType>
IUnit* UnitManager<UnitType>::getUnit() {
    return this->unit;
}

template <typename UnitType>
UnitType* UnitManager<UnitType>::getBase() {
    return this->base;
}

template <typename UnitType>
void UnitManager<UnitType>::buff(BuffDecorator *decorator) {
    this->unit = decorator;
}


#endif //GRIMWALL_UNITMANAGER_H
