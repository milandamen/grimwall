
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>

class AUnit {
protected:
    std::string name;
    int reach;
    int attackDelay;
    int power;
    int hitPoints;
public:
    AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints);
    AUnit();
    ~AUnit();

    virtual std::string getName();
    virtual int getReach();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual void doDamage(int power) = 0;
};


#endif