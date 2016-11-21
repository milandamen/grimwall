#ifndef GRIMWALL_ABUFF_H
#define GRIMWALL_ABUFF_H

#include "../IUnit.h"

class ABuff {
protected:
    // duration in milliseconds
    int duration;

    IUnit *unit;
public:
    ABuff(int duration, IUnit *unit);
    ~ABuff();
};

#endif //GRIMWALL_ABUFF_H
