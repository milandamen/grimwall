#ifndef GRIMWALL_ARMOUREDTOWER_H
#define GRIMWALL_ARMOUREDTOWER_H

#include "ATower.h"

class ArmouredTower : public ATower{
    ArmouredTower();
    ~ArmouredTower();
    virtual void doDamage(int power);
};


#endif //GRIMWALL_ARMOUREDTOWER_H
