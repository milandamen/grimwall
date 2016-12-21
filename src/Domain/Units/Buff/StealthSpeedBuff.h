#ifndef GRIMWALL_STEALTHSPEEDBUFF_H
#define GRIMWALL_STEALTHSPEEDBUFF_H


#include "BuffDecorator.h"

class StealthSpeedBuff : public BuffDecorator{
private:
    int multiplier;

public:
    StealthSpeedBuff(IUnit *inner, int multplier);

    double getSpeed();
};


#endif //GRIMWALL_STEALTHSPEEDBUFF_H
