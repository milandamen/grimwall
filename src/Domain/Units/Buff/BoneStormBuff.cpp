#include "BoneStormBuff.h"

BoneStormBuff::BoneStormBuff(int multiplier)
        : BuffDecorator("Bone Storm", 300), multiplier{multiplier}
{}

int BoneStormBuff::getAttackDelay()
{
    return BuffDecorator::getAttackDelay() * this->multiplier;
}
