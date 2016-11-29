#ifndef GRIMWALL_UNITDECORATOR_H
#define GRIMWALL_UNITDECORATOR_H

#include "../IUnit.h"

class BuffDecorator : public IUnit {
private:
    IUnit *m_wrappee;
protected:
    int duration;
public:
    BuffDecorator(IUnit *inner, int duration);
    ~BuffDecorator(){};

    std::string getName();
    int getReach();
    int getAttackDelay();
    int getPower();
    int getHitPoints();
    int getSpeed();
    int getVisibility();
    void doDamage(int power);

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

    void remove();
};


#endif //GRIMWALL_UNITDECORATOR_H
