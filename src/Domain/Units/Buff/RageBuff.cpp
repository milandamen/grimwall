//
// Created by baksteen on 10/25/16.
//

#include "RageBuff.h"

RageBuff::RageBuff(IUnit *inner, int multiplier)
        : BuffDecorator{inner, 2000}, multiplier{multiplier}
{}

int RageBuff::getAttackDelay() {
    return BuffDecorator::getAttackDelay() / this->multiplier;
}
