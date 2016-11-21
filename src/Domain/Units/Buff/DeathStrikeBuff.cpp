#include "DeathStrikeBuff.h"

DeathStrikeBuff::DeathStrikeBuff(IUnit *inner, int multiplier)
        : BuffDecorator(inner), multiplier{multiplier}
{}

int DeathStrikeBuff::getPower()
{
    return BuffDecorator::getPower() * this->multiplier;
}