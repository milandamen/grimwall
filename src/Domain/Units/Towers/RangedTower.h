#ifndef GRIMWALL_RANGEDTOWER_H
#define GRIMWALL_RANGEDTOWER_H


#include "ATower.h"

class RangedTower : public ATower{
    RangedTower();
    ~RangedTower();
    virtual void doDamage(int power);
};


#endif //GRIMWALL_RANGEDTOWER_H
