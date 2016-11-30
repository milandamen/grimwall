#include "BoneStormBuff.h"

BoneStormBuff::BoneStormBuff(IUnit* inner)
        : BuffDecorator(inner, 300)
{}

int BoneStormBuff::getAttackDelay()
{
    return BuffDecorator::getAttackDelay() * 2;
}
