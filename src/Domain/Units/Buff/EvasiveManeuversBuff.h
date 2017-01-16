

#ifndef GRIMWALL_EVASIVEMANEUVERSBUFF_H
#define GRIMWALL_EVASIVEMANEUVERSBUFF_H


#include "BuffDecorator.h"

class EvasiveManeuversBuff : public BuffDecorator{
private:
    int multiplier;

public:
    EvasiveManeuversBuff(int multplier);

    double getSpeed();
    int getVisibility();
};


#endif //GRIMWALL_EVASIVEMANEUVERSBUFF_H
