#include "StealthSpeedBuff.h"

StealthSpeedBuff::StealthSpeedBuff(IUnit *inner, int multplier)
        : BuffDecorator{inner}, multiplier{multplier}
{}

int StealthSpeedBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}