#ifndef GRIMWALL_IUNIT_H
#define GRIMWALL_IUNIT_H

#include <iostream>

class IUnit {
public:
    virtual ~IUnit() = default;
    virtual std::string getName() = 0;
    virtual double getReach() = 0;
    virtual int getAttackDelay() = 0;
    virtual int getPower() = 0;
    virtual int getHitPoints() = 0;
    virtual double getSpeed() = 0;
    virtual int getVisibility() = 0;
    virtual void receiveDamage(int power) = 0;

    virtual double getX() = 0;
    virtual void setX(double x) = 0;
    virtual double getY() = 0;
    virtual void setY(double y) = 0;
};


#endif //GRIMWALL_IUNIT_H
