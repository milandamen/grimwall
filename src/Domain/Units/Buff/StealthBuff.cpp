#include "StealthBuff.h"

StealthBuff::StealthBuff(int multiplier)
        : BuffDecorator("Stealth", 300), multiplier{multiplier}
{}

double StealthBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}

int StealthBuff::getVisibility()
{
    return 15;
}