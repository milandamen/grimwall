#ifndef GRIMWALL_TOWER_H
#define GRIMWALL_TOWER_H

#include "../AUnit.h"


class ATower : AUnit {
private:

public:
    ATower(std::string name, int reach, int attackDelay, int power, int hitPoints);
    ~ATower();
    virtual void doDamage(int power);
};


#endif //GRIMWALL_TOWER_H
