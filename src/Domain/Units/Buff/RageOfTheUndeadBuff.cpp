#include "RageOfTheUndeadBuff.h"

RageOfTheUndeadBuff::RageOfTheUndeadBuff(int multiplier)
        : BuffDecorator("Rage of the Undead", 300), multiplier{multiplier}
{
}

double RageOfTheUndeadBuff::getSpeed() {
    return BuffDecorator::getSpeed() * this->multiplier;
}

int RageOfTheUndeadBuff::getPower() {
    return BuffDecorator::getPower() * this->multiplier;
}