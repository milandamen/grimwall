#include "SmokeBomb.h"
#include "../../Buff/SmokeBombBuff.h"

SmokeBomb::SmokeBomb(UnitManager<AHero>* hero)
        : AAbility("Smoke Bomb", 15), hero{hero}
{
    
}

int SmokeBomb::execute()
{
    this->hero->buff(new SmokeBombBuff());
    return 1;

}

