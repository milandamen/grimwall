#include "RageOfTheUndead.h"
#include "../../Buff/RageOfTheUndeadBuff.h"

RageOfTheUndead::RageOfTheUndead(vector<IUnit*> troups)
    :AAbility(50), troups{troups}
{

}

int RageOfTheUndead::execute() {
    for (int i = 0; i < this->troups.size(); ++i)
        this->troups[i] = new RageOfTheUndeadBuff(this->troups[i], 2);
    return 1;
}
