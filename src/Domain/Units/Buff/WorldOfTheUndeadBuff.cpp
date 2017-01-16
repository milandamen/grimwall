

#include "WorldOfTheUndeadBuff.h"

WorldOfTheUndeadBuff::WorldOfTheUndeadBuff(IUnit *inner, int multiplier)
        : BuffDecorator(inner, 500), multiplier{multiplier}
{
}

double WorldOfTheUndeadBuff::getSpeed() {
    return BuffDecorator::getSpeed() * this->multiplier;
}

int WorldOfTheUndeadBuff::getAttackDelay() {
    return BuffDecorator::getAttackDelay() / this->multiplier;
}