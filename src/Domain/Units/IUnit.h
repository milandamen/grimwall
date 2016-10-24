//
// Created by roel on 24-10-16.
//

#ifndef GRIMWALL_IUNIT_H
#define GRIMWALL_IUNIT_H

#include <iostream>

class IUnit {
public:
    virtual std::string getName();
    virtual int getReach();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual void doDamage(int power) = 0;
};


#endif //GRIMWALL_IUNIT_H
