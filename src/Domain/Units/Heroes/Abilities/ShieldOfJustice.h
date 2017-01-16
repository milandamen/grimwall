

#ifndef GRIMWALL_SHIELDOFJUSTICE_H
#define GRIMWALL_SHIELDOFJUSTICE_H


#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class ShieldOfJustice  : public AAbility {
private:
    UnitManager<AHero>* hero;
public:
    ShieldOfJustice(UnitManager<AHero>* hero);

    int execute();
};


#endif //GRIMWALL_SHIELDOFJUSTICE_H
