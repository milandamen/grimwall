#ifndef GRIMWALL_DEATHSTRIKE_H
#define GRIMWALL_DEATHSTRIKE_H

#include "../AAbility.h"
#include "../AHero.h"

class DeathStrike : public AAbility {
private:
    IUnit* hero;
public:
    DeathStrike(IUnit* hero);

    int execute();
};


#endif //GRIMWALL_DEATHSTRIKE_H
