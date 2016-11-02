#ifndef GRIMWALL_STEALTHVISIBILITYBUFF_H
#define GRIMWALL_STEALTHVISIBILITYBUFF_H


#include "BuffDecorator.h"

class StealthVisibilityBuff : public BuffDecorator{


private:

public:
    StealthVisibilityBuff(IUnit* inner);

    int getVisibility();
};


#endif //GRIMWALL_STEALTHVISIBILITYBUFF_H
