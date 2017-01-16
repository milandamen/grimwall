

#ifndef GRIMWALL_WORLDOFTHEUNDEADBUFF_H
#define GRIMWALL_WORLDOFTHEUNDEADBUFF_H


#include "BuffDecorator.h"

class WorldOfTheUndeadBuff : public BuffDecorator {
private:
    int multiplier;
public:
    WorldOfTheUndeadBuff(int multiplier);
    double getSpeed() override;
    int getAttackDelay() override;
};


#endif //GRIMWALL_WORLDOFTHEUNDEADBUFF_H
