//
// Created by baksteen on 10/24/16.
//

#ifndef GRIMWALL_EXECUTIONBUFF_H
#define GRIMWALL_EXECUTIONBUFF_H

#include "BuffDecorator.h"

class ExecutionBuff : public BuffDecorator{

private:
    IUnit *target;

public:
    ExecutionBuff(IUnit *inner, IUnit *target);
    ~ExecutionBuff();

    void execute();

};

#endif //GRIMWALL_EXECUTIONBUFF_H
