

#include "RageBuff.h"

RageBuff::RageBuff(int multplier)
        : BuffDecorator{"Rage", 300}, multiplier{multplier}
{}

int RageBuff::getAttackDelay() {
    return BuffDecorator::getAttackDelay() / this->multiplier;
}