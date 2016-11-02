#include "BoneStormBuff.h"

BoneStormBuff::BoneStormBuff(IUnit* inner, int multiplier)
        : BuffDecorator(inner, 300), multiplier{multiplier}
{}

int BoneStormBuff::getAttackDelay()
{
    return BuffDecorator::getAttackDelay() * this->multiplier;
}
