#include "StealthVisibilityBuff.h"

StealthVisibilityBuff::StealthVisibilityBuff(IUnit *inner)
        : BuffDecorator{inner, 3000}
{}

int StealthVisibilityBuff::getVisibility()
{
    return 0;
}