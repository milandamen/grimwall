#include "Stealth.h"
#include "../../Buff/StealthBuff.h"
#include "../../Buff/StealthVisibilityBuff.h"

Stealth::Stealth(UnitManager<AHero>* hero)
        : AAbility("Stealth", 75), hero{hero}
{}

int Stealth::execute()
{
    this->hero->buff(new StealthBuff(this->hero->getUnit(), 2));
    return 1;
}
