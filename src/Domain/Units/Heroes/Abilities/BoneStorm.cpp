#include "BoneStorm.h"
#include "../../Buff/BoneStormBuff.h"

BoneStorm::BoneStorm(vector<IUnit*> towers)
        : towers{towers}, AAbility(40)
{
}


int BoneStorm::execute()
{
    for (int i = 0; i < this->towers.size(); ++i)
        this->towers[i] = new BoneStormBuff(this->towers[i], 2);
    return 1;
}