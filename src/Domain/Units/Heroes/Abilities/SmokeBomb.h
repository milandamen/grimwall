#ifndef GRIMWALL_SMOKEBOMB_H
#define GRIMWALL_SMOKEBOMB_H


#include <vector>
#include "../AAbility.h"
#include "../../IUnit.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class SmokeBomb : public AAbility{

private:
    UnitManager<AHero>* hero;
public:
    SmokeBomb(UnitManager<AHero>* hero);

    int execute();
};


#endif //GRIMWALL_SMOKEBOMB_H
