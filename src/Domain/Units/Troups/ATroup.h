#ifndef GRIMWALL_ATROUP_H
#define GRIMWALL_ATROUP_H


#include "../AUnit.h"
#include "../Towers/ATower.h"
#include "../UnitManager.hpp"

class ATroup : public AUnit {
private:

public:
    ATroup(std::string name, int reach, int attackDelay, int moveSpeed, int power,
               int hitPoints, int visibility);
    UnitManager<ATower>* target {nullptr};
};


#endif
