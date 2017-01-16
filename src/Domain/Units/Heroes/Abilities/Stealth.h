#ifndef GRIMWALL_STEALTH_H
#define GRIMWALL_STEALTH_H



#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"

class Stealth : public AAbility{

private:
    UnitManager<AHero>* hero;
public:
    Stealth(UnitManager<AHero>* hero);

    int execute();

};


#endif //GRIMWALL_STEALTH_H
