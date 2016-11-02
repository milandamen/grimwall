#include "DeathStrike.h"
#include "../../Buff/DeathStrikeBuff.h"

DeathStrike::DeathStrike(IUnit* hero)
        : hero{hero}, AAbility(25)
{

}

int DeathStrike::execute() {
    hero = new DeathStrikeBuff(hero, 2);
    return 1;
}

IUnit* DeathStrike::getHero() {
    return hero;
}
