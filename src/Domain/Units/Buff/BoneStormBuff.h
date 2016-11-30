#ifndef GRIMWALL_BONESTORMBUFF_H
#define GRIMWALL_BONESTORMBUFF_H

#include "BuffDecorator.h"

class BoneStormBuff : public BuffDecorator {
private:
    int multiplier;
public:
    BoneStormBuff(IUnit *inner, int multiplier);

    int getAttackDelay();

};


#endif //GRIMWALL_BONESTORMBUFF_H
