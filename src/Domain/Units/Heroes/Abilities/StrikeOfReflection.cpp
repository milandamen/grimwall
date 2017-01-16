

#include "StrikeOfReflection.h"
#include "../../Buff/StrikeOfReflectionBuff.h"

StrikeOfReflection::StrikeOfReflection(UnitManager <AHero> *hero)
        : AAbility("StrikeOfReflection", 25), hero{hero}
{}

int StrikeOfReflection::execute() {
    this->hero->buff(new StrikeOfReflectionBuff(2));
    return 1;
}