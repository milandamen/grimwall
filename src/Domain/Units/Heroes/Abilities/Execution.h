

#ifndef GRIMWALL_EXECUTION_H
#define GRIMWALL_EXECUTION_H

#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"
#include "../../Towers/ATower.h"

class Execution : public AAbility {
private:
    UnitManager<AHero>* hero;
    std::vector<UnitManager<ATower> *>* towers;
public:
    Execution(UnitManager<AHero>* hero, std::vector<UnitManager<ATower> *>* towers);

    int execute();
};


#endif //GRIMWALL_EXECUTION_H
