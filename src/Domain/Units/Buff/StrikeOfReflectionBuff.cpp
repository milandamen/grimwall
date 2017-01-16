

#include "StrikeOfReflectionBuff.h"

StrikeOfReflectionBuff::StrikeOfReflectionBuff(int multiplier)
        : BuffDecorator("Strike of Reflection", 300), multiplier{multiplier}
{}

int StrikeOfReflectionBuff::getPower()
{
    return BuffDecorator::getPower() * this->multiplier;
}

int StrikeOfReflectionBuff::getVisibility() {
    return 0;
}