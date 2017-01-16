#include "EvasiveManeuvers.h"
#include "../../Buff/EvasiveManeuversBuff.h"

EvasiveManeuvers::EvasiveManeuvers(UnitManager<AHero>* hero)
        : AAbility("Evasive Maneuvers", 15), hero{hero}
{}

int EvasiveManeuvers::execute()
{
    this->hero->buff(new EvasiveManeuversBuff(2));
    return 1;
}