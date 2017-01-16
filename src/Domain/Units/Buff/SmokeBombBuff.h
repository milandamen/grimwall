#ifndef GRIMWALL_SMOKEBOMBBUFF_H
#define GRIMWALL_SMOKEBOMBBUFF_H

#include "BuffDecorator.h"

class SmokeBombBuff : public BuffDecorator {
private:

public:
    SmokeBombBuff(IUnit *inner);

    int getVisibility();
};


#endif //GRIMWALL_SMOKEBOMBBUFF_H
