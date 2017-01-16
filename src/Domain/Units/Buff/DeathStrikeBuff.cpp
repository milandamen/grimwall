#include "DeathStrikeBuff.h"

DeathStrikeBuff::DeathStrikeBuff(int multiplier)
        : BuffDecorator("Death Strike", 300), multiplier{multiplier}
{}

int DeathStrikeBuff::getPower()
{
    return BuffDecorator::getPower() * this->multiplier;
}