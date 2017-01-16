#ifndef GRIMWALL_RAISEUNDEAD_H
#define GRIMWALL_RAISEUNDEAD_H

#include <iostream>
#include <vector>
#include "../AAbility.h"
#include "../../UnitManager.hpp"
#include "../AHero.h"

using std::vector;

class WorldOfTheUndead : public AAbility {
private:
    UnitManager<AHero>* hero;
public:
    WorldOfTheUndead(UnitManager<AHero>* hero);
    int execute();
};


#endif //GRIMWALL_RAISEUNDEAD_H
