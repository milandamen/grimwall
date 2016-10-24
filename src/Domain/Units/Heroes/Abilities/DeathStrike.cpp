#include "DeathStrike.h"
#include "../../Buff/DeathStrikeBuff.h"

DeathStrike::DeathStrike(IUnit* hero)
    : AAbility(25), hero{hero}
{

}

int DeathStrike::execute() {
    hero = new DeathStrikeBuff(hero, 2);
    return 1;
}
