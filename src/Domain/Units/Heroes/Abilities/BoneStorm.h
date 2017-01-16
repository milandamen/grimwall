#ifndef GRIMWALL_BONESTORM_H
#define GRIMWALL_BONESTORM_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../../UnitManager.hpp"
#include "../../Towers/ATower.h"

using std::vector;

class BoneStorm : public AAbility {
private:
    std::vector<UnitManager<ATower> *>* towers;
public:
    BoneStorm(std::vector<UnitManager<ATower> *>* towers);
    int execute();
};


#endif //GRIMWALL_BONESTORM_H
