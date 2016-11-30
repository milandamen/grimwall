#include "BoneStorm.h"
#include "../../Buff/BoneStormBuff.h"

BoneStorm::BoneStorm(vector<IUnit*> towers)
        : AAbility(40), towers{towers}
{
    
}


int BoneStorm::execute()
{
    for (size_t i = 0; i < this->towers.size(); ++i)
        this->towers[i] = new BoneStormBuff(this->towers[i]);
    return 1;
}