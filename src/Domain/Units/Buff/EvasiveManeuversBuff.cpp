

#include "EvasiveManeuversBuff.h"

EvasiveManeuversBuff::EvasiveManeuversBuff(IUnit *inner, int multplier)
        : BuffDecorator{inner, 300}, multiplier{multplier}
{}

double EvasiveManeuversBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}

int EvasiveManeuversBuff::getVisibility()
{
    return 0;
}