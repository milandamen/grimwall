//
// Created by roel on 2-11-16.
//

#include "RageOfTheUndeadBuff.h"

RageOfTheUndeadBuff::RageOfTheUndeadBuff(IUnit *inner, int multiplier)
        : BuffDecorator(inner, 300), multiplier{multiplier}
{
}

int RageOfTheUndeadBuff::getPower() {
    return BuffDecorator::getPower() * this->multiplier;
}