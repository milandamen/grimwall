#ifndef GRIMWALL_BONESTORMBUFF_H
#define GRIMWALL_BONESTORMBUFF_H

#include "BuffDecorator.h"

class BoneStormBuff : public BuffDecorator {
public:
    BoneStormBuff(IUnit *inner);

    int getAttackDelay();

};


#endif //GRIMWALL_BONESTORMBUFF_H
