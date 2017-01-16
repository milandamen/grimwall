

#ifndef GRIMWALL_RAGEBUFF_H
#define GRIMWALL_RAGEBUFF_H

#include "BuffDecorator.h"

class RageBuff : public BuffDecorator{
private:
    int multiplier;

public:
    RageBuff(int multplier);

    int getAttackDelay();
};


#endif //GRIMWALL_RAGEBUFF_H
