#include "DeathStrike.h"
#include "../../Buff/DeathStrikeBuff.h"

DeathStrike::DeathStrike(UnitManager<AHero>* hero)
        : AAbility(25), hero{hero}
{
    
}

int DeathStrike::execute() {
    hero->buff(new DeathStrikeBuff(hero->getUnit(), 2));
    return 1;
}
