#include "Stealth.h"
#include "../../Buff/StealthSpeedBuff.h"

Stealth::Stealth(IUnit *hero)
        : AAbility(40), hero{hero}
{}

int Stealth::execute()
{
    hero = new StealthSpeedBuff(this->hero, 2);

    return 1;
}
