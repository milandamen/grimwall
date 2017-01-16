

#ifndef GRIMWALL_STRIKEOFREFLECTION_H
#define GRIMWALL_STRIKEOFREFLECTION_H


#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class StrikeOfReflection : public AAbility {
private:
    UnitManager<AHero>* hero;
public:
    StrikeOfReflection(UnitManager<AHero>* hero);

    int execute();
};


#endif //GRIMWALL_STRIKEOFREFLECTION_H
