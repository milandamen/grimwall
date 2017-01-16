#ifndef GRIMWALL_DEADSTRIKE_H
#define GRIMWALL_DEADSTRIKE_H

#include "BuffDecorator.h"

class DeathStrikeBuff : public BuffDecorator {
private:
    int multiplier;
public:
    DeathStrikeBuff(int multiplier);

    int getPower();
};


#endif //GRIMWALL_DEADSTRIKE_H
