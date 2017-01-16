#ifndef GRIMWALL_EVASIVEMANEUVERS_H
#define GRIMWALL_EVASIVEMANEUVERS_H


#include "../AHero.h"
#include "../AAbility.h"
#include "../../UnitManager.hpp"

class EvasiveManeuvers : public AAbility{

private:
    UnitManager<AHero>* hero;
public:
    EvasiveManeuvers(UnitManager<AHero>* hero);

    int execute();

};


#endif //GRIMWALL_EVASIVEMANEUVERS_H
