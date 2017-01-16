

#include "Rage.h"
#include "../../Buff/RageBuff.h"

Rage::Rage(UnitManager <AHero> *hero)
        : AAbility("Rage", 40), hero{hero}
{}

int Rage::execute() {
    this->hero->buff(new RageBuff(2));
    return 1;
}