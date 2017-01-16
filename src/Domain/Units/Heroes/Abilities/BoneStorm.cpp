#include "BoneStorm.h"
#include "../../Buff/BoneStormBuff.h"

BoneStorm::BoneStorm(std::vector<UnitManager<ATower>*>* towers)
        : AAbility("Bone Storm", 40), towers{towers}
{
    
}


int BoneStorm::execute()
{
    UnitManager<ATower> *tower;
    for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end(); ++it) {
        tower = *it;
        tower->buff(new BoneStormBuff(2));
    }
    return 1;
}