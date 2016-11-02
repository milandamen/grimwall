#include "Stealth.h"
#include "../../Buff/StealthSpeedBuff.h"
#include "../../Buff/StealthVisibilityBuff.h"

Stealth::Stealth(IUnit *hero)
        : AAbility(40), hero{hero}
{}

int Stealth::execute()
{
    hero = new StealthSpeedBuff(this->hero, 2);
    hero = new StealthVisibilityBuff(this->hero);
    return 1;
}
