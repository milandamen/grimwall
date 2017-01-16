#include "RageOfTheUndead.h"
#include "../../Buff/RageOfTheUndeadBuff.h"

RageOfTheUndead::RageOfTheUndead(std::vector<UnitManager<ATroup>*>* troups)
    :AAbility("Rage of the Undead", 50), troups{troups}
{

}

int RageOfTheUndead::execute() {
    UnitManager<ATroup> *troup;
    for (std::vector<UnitManager<ATroup> *>::iterator it = troups->begin(); it != troups->end(); ++it) {
        troup = *it;
        troup->buff(new RageOfTheUndeadBuff(2));
    }
    return 1;
}
