#ifndef GRIMWALL_UNITDECORATOR_H
#define GRIMWALL_UNITDECORATOR_H

#include "../IUnit.h"

class BuffDecorator : public IUnit {
private:
    IUnit *next;
    IUnit *previous;
protected:
    int duration;
    int time;
public:
    BuffDecorator(IUnit *next, int duration);
    ~BuffDecorator();

    std::string getName();
    double getReach();
    int getAttackDelay();
    int getPower();
    int getHitPoints();
    double getSpeed();
    int getVisibility();
    void receiveDamage(int power);

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

    void setNext(IUnit *next);
    void setPrevious(IUnit *previous);

    void tick() override ;
};


#endif //GRIMWALL_UNITDECORATOR_H
