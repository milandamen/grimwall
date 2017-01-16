#ifndef GRIMWALL_RAGEOFTHEUNDEAD_H
#define GRIMWALL_RAGEOFTHEUNDEAD_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../../UnitManager.hpp"
#include "../../Troups/ATroup.h"

using std::vector;

class RageOfTheUndead : public AAbility {
private:
    std::vector<UnitManager<ATroup>*>* troups;
public:
    RageOfTheUndead(std::vector<UnitManager<ATroup>*>* troups);
    int execute();
};


#endif //GRIMWALL_RAGEOFTHEUNDEAD_H
