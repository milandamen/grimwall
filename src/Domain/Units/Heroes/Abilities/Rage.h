

#ifndef GRIMWALL_RAGE_H
#define GRIMWALL_RAGE_H


#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class Rage : public AAbility {
private:
    UnitManager<AHero>* hero;
public:
    Rage(UnitManager<AHero>* hero);

    int execute();
};


#endif //GRIMWALL_RAGE_H
