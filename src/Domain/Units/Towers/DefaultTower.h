#ifndef GRIMWALL_DEFAULTTOWER_H
#define GRIMWALL_DEFAULTTOWER_H

#include "ATower.h"

class DefaultTower : public ATower {
    DefaultTower();
    ~DefaultTower();
    virtual void doDamage(int power);
};


#endif //GRIMWALL_DEFAULTTOWER_H
