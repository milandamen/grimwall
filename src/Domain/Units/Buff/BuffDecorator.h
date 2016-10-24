#ifndef GRIMWALL_UNITDECORATOR_H
#define GRIMWALL_UNITDECORATOR_H

#include "../IUnit.h"


class BuffDecorator : public IUnit {
private:
    IUnit *m_wrappee;
protected:
    int duration;
public:
    BuffDecorator(IUnit *inner);
    ~BuffDecorator(){};

    std::string getName();
    int getReach();
    int getAttackDelay();
    int getPower();
    int getHitPoints();
    void doDamage(int power);

    void remove();
};


#endif //GRIMWALL_UNITDECORATOR_H
