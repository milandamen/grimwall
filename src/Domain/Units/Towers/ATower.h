#ifndef GRIMWALL_TOWER_H
#define GRIMWALL_TOWER_H

#include "../AUnit.h"


class ATower : public AUnit {
private:
public:
    virtual void doDamage(int power);
};


#endif //GRIMWALL_TOWER_H
