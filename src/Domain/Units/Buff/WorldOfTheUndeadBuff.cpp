

#include "WorldOfTheUndeadBuff.h"

WorldOfTheUndeadBuff::WorldOfTheUndeadBuff(int multiplier)
        : BuffDecorator("World of the Undead", 500), multiplier{multiplier}
{
}

double WorldOfTheUndeadBuff::getSpeed() {
    return BuffDecorator::getSpeed() * this->multiplier;
}

int WorldOfTheUndeadBuff::getAttackDelay() {
    return BuffDecorator::getAttackDelay() / this->multiplier;
}