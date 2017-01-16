#include "StealthBuff.h"

StealthBuff::StealthBuff(IUnit *inner, int multplier)
        : BuffDecorator{inner, 3000}, multiplier{multplier}
{}

double StealthBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}

int StealthBuff::getVisibility()
{
    return 0;
}