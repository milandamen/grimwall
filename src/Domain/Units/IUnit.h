#ifndef GRIMWALL_IUNIT_H
#define GRIMWALL_IUNIT_H

#include <iostream>

class IUnit {
public:
    virtual std::string getName() = 0;
    virtual int getReach() = 0;
    virtual int getAttackDelay() = 0;
    virtual int getPower() = 0;
    virtual int getHitPoints() = 0;
    virtual void doDamage(int power) = 0;
};


#endif //GRIMWALL_IUNIT_H
