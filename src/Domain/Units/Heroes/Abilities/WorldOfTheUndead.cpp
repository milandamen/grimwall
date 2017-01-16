#include "WorldOfTheUndead.h"
#include "../../Buff/WorldOfTheUndeadBuff.h"

WorldOfTheUndead::WorldOfTheUndead(UnitManager<AHero>* hero)
        :AAbility("WorldOfTheUndead", 70), hero{hero}
{}

int WorldOfTheUndead::execute() {
    this->hero->buff(new WorldOfTheUndeadBuff(2));

    return 1;
}
