#include "StealthSpeedBuff.h"

StealthSpeedBuff::StealthSpeedBuff(IUnit *inner, int multplier)
        : BuffDecorator{inner, 3000}, multiplier{multplier}
{}

int StealthSpeedBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}