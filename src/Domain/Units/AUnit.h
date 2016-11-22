
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>
#include "IUnit.h"

class AUnit : public IUnit {
protected:
    std::string name;
    int reach;
    int attackDelay;
    int power;
    int hitPoints;
    int speed;
    int visibility;
public:
    AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints, int speed,
    int visibility);
    ~AUnit();

    virtual std::string getName();
    virtual int getReach();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual int getSpeed();
    virtual int getVisibility();
    virtual void doDamage(int power) = 0;
};


#endif