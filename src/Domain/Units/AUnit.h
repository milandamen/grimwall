
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
    int originalHitPoints;

public:
    AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints);
    virtual ~AUnit();

    virtual std::string getName() = 0;
    virtual int getReach() = 0;
    virtual int getAttackDelay() = 0;
    virtual int getPower() = 0;
    virtual int getHitPoints() = 0;
    virtual int getOriginalHitPoints() = 0;
    virtual void doDamage(int power) = 0;
};


#endif