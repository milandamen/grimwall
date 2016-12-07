#ifndef GRIMWALL_DEATHSTRIKE_H
#define GRIMWALL_DEATHSTRIKE_H

#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class DeathStrike : public AAbility {
private:
    UnitManager<AHero>* hero;
public:
    DeathStrike(UnitManager<AHero>* hero);
    int execute();
};


#endif //GRIMWALL_DEATHSTRIKE_H
