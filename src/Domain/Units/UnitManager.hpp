

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
protected:
    std::function<void()> updateStatsListener = [](){};
public:
    UnitManager(UnitType* unit);
    ~UnitManager();

    std::string getName() override;
    double getReach() override;
    int getAttackDelay() override;
    int getPower() override;
    int getHitPoints() override;
    double getSpeed() override;
    int getVisibility() override;
    void receiveDamage(int power) override;
    void setInvincible(bool invincible) override;
    std::vector<std::string> getBuffs() override;
    void setInvisible(bool invisible) override;

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;

    void setNext(IUnit *next) override;
    void setPrevious(IUnit *previous) override;

    bool attack() override;

    bool canAttack() override;

    void tick() override;

    UnitType* getBase();
    IUnit* getUnit();

    void buff(BuffDecorator* decorator);

    void setStatsListener(std::function<void()> delegate) override;
};

template <typename UnitType>
UnitManager<UnitType>::UnitManager(UnitType *unit)
        : base{unit}, unit{unit}
{
    this->unit->setPrevious(this);
}

template <typename UnitType>
UnitManager<UnitType>::~UnitManager() {
    delete this->unit;
}

template <typename UnitType>
std::string UnitManager<UnitType>::getName() {
    return unit->getName();
}

template <typename UnitType>
double UnitManager<UnitType>::getReach() {
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
double UnitManager<UnitType>::getSpeed() {
    return unit->getSpeed();
}

template <typename UnitType>
int UnitManager<UnitType>::getVisibility() {
    return unit->getVisibility();
}

template <typename UnitType>
std::vector<std::string> UnitManager<UnitType>::getBuffs() {
    return unit->getBuffs();
}

template <typename UnitType>
void UnitManager<UnitType>::receiveDamage(int power) {
    unit->receiveDamage(power);
}

template <typename UnitType>
void UnitManager<UnitType>::setInvincible(bool invincible) {
    base->setInvincible(invincible);
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
bool UnitManager<UnitType>::attack() {
    return unit->attack();
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
void UnitManager<UnitType>::setNext(IUnit *next) {
    this->unit = next;
}

template <typename UnitType>
void UnitManager<UnitType>::setPrevious(IUnit *previous) {}

template <typename UnitType>
void UnitManager<UnitType>::tick() {
    this->unit->tick();
}

template <typename UnitType>
void UnitManager<UnitType>::buff(BuffDecorator *decorator) {
    decorator->setNext(this->unit);
    this->unit = decorator;
    this->unit->setPrevious(this);

    this->updateStatsListener();
}

template <typename UnitType>
void UnitManager<UnitType>::setStatsListener(std::function<void()> delegate) {
    this->updateStatsListener = delegate;
    this->unit->setStatsListener(delegate);
}

template <typename UnitType>
bool UnitManager<UnitType>::canAttack() {
    return unit->canAttack();
}

template <typename UnitType>
void UnitManager<UnitType>::setInvisible(bool invisible){
    unit->setInvisible(invisible);
}

#endif //GRIMWALL_UNITMANAGER_H
