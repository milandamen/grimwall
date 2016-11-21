#include "RageOfTheUndeadBuff.h"

RageOfTheUndeadBuff::RageOfTheUndeadBuff(IUnit *inner, int multiplier)
        : BuffDecorator(inner), multiplier{multiplier}
{
}

int RageOfTheUndeadBuff::getPower() {
    return BuffDecorator::getPower() * this->multiplier;
}