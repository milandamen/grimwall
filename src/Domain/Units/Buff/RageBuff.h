//
// Created by baksteen on 10/25/16.
//

#ifndef GRIMWALL_RAGEBUFF_H
#define GRIMWALL_RAGEBUFF_H

#include "BuffDecorator.h"

class RageBuff : public BuffDecorator{
private:
    int multiplier;

public:
    RageBuff(IUnit *inner, int multiplier);
    ~RageBuff();

    int getAttackDelay();

};

#endif //GRIMWALL_RAGEBUFF_H
