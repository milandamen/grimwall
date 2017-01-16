

#ifndef GRIMWALL_STRIKEOFREFLECTIONBUFF_H
#define GRIMWALL_STRIKEOFREFLECTIONBUFF_H


#include "BuffDecorator.h"

class StrikeOfReflectionBuff : public BuffDecorator {
private:
    int multiplier;

public:
    StrikeOfReflectionBuff(int multplier);

    int getPower();
    int getVisibility();
};


#endif //GRIMWALL_STRIKEOFREFLECTIONBUFF_H
