

#include "EvasiveManeuversBuff.h"

EvasiveManeuversBuff::EvasiveManeuversBuff(int multplier)
        : BuffDecorator("Evasive Maneuvers", 30), multiplier{multplier}
{}

double EvasiveManeuversBuff::getSpeed()
{
    return BuffDecorator::getSpeed() * multiplier;
}

int EvasiveManeuversBuff::getVisibility()
{
    return 50;
}