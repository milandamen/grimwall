#ifndef GRIMWALL_UNITDECORATOR_H
#define GRIMWALL_UNITDECORATOR_H

#include "../IUnit.h"

class BuffDecorator{
private:
    IUnit *m_wrappee;
public:
    BuffDecorator(IUnit *inner);
    ~BuffDecorator(){};

    std::string getName();
    int getReach();
    int getAttackDelay();
    int getPower();
    int getHitPoints();
    int getSpeed();
    int getVisibility();
    void doDamage(int power);

    void remove();
};


#endif //GRIMWALL_UNITDECORATOR_H
