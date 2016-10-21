
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>

class AUnit {
private:
    std::string name;
    int reach;
    int attackDelay;
    int power;
    int hitPoints;
public:
    virtual std::string getName() = 0;
    virtual int getReach() = 0;
    virtual int getAttackDelay() = 0;
    virtual int getPower() = 0;
    virtual int getHitPoints() = 0;
    virtual void doDamage(int power);
};


#endif