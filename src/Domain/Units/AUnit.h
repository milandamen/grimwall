
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>
#include "IUnit.h"

class AUnit : public IUnit {
protected:
    std::string name;
    int range;
    int attackDelay;
    int power;
    int hitPoints;
    bool is_alive = false;
public:
    AUnit(std::string name, int range, int attackDelay, int power, int hitPoints);
    ~AUnit();

    virtual std::string getName();
    virtual int getRange();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual bool isAlive() = 0;
    virtual void attack(AUnit* unit);
    virtual void inflictDamage(int hitPoints);
};


#endif