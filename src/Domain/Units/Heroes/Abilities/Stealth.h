#ifndef GRIMWALL_STEALTH_H
#define GRIMWALL_STEALTH_H


#include "../AHero.h"
#include "../AAbility.h"

class Stealth : AAbility{

private:
    IUnit *hero;

public:
    Stealth(IUnit *hero);

    int execute();

};


#endif //GRIMWALL_STEALTH_H
