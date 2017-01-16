

#include "ShieldOfJustice.h"
#include "../../Buff/ShieldOfJusticeBuff.h"

ShieldOfJustice::ShieldOfJustice(UnitManager <AHero> *hero)
        : AAbility("Shield Of Justice", 60), hero{hero}
{}

int ShieldOfJustice::execute() {
    this->hero->buff(new ShieldOfJusticeBuff());
    return 1;
}