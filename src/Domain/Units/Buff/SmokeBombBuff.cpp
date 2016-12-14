#include "SmokeBombBuff.h"

SmokeBombBuff::SmokeBombBuff(IUnit *inner, int divisor)
        : BuffDecorator{inner, 5000}, divisor{divisor}
{}

double SmokeBombBuff::getReach()
{
    return BuffDecorator::getReach() / this->divisor;
}