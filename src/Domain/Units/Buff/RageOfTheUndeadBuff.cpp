#include "RageOfTheUndeadBuff.h"

RageOfTheUndeadBuff::RageOfTheUndeadBuff(IUnit *inner, int multiplier)
        : BuffDecorator(inner, 300), multiplier{multiplier}
{
}

int RageOfTheUndeadBuff::getPower() {
    return BuffDecorator::getPower() * this->multiplier;
}