#ifndef GRIMWALL_SMOKEBOMBBUFF_H
#define GRIMWALL_SMOKEBOMBBUFF_H

#include "BuffDecorator.h"

class SmokeBombBuff : public BuffDecorator {
private:
    int divisor;

public:
    SmokeBombBuff(IUnit *inner, int divisor);

    double getReach();

};


#endif //GRIMWALL_SMOKEBOMBBUFF_H
