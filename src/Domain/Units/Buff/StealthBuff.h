#ifndef GRIMWALL_STEALTHSPEEDBUFF_H
#define GRIMWALL_STEALTHSPEEDBUFF_H


#include "BuffDecorator.h"

class StealthBuff : public BuffDecorator{
private:
    int multiplier;

public:
    StealthBuff(int multiplier);

    double getSpeed();
    int getVisibility();
};


#endif //GRIMWALL_STEALTHSPEEDBUFF_H
