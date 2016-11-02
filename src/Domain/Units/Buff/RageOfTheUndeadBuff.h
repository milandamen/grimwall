#ifndef GRIMWALL_RAGEOFTHEUNDEADBUFF_H
#define GRIMWALL_RAGEOFTHEUNDEADBUFF_H

#include "BuffDecorator.h"

class RageOfTheUndeadBuff : public BuffDecorator {
private:
    int multiplier;
public:
    RageOfTheUndeadBuff(IUnit *inner, int multiplier);
    int getPower();
};


#endif //GRIMWALL_RAGEOFTHEUNDEADBUFF_H
