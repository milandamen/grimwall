
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>
#include "IUnit.h"

class AUnit : public IUnit {
protected:
    std::string name;
    int reach;
    int attackDelay;
    int power;
    int hitPoints;
    int speed;
    int visibility;

    double x{0};
    double y{0};
public:
    AUnit(std::string name, int reach, int attackDelay, int power, int hitPoints, int speed,
    int visibility);
    ~AUnit();

    virtual std::string getName();
    virtual int getReach();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual int getSpeed();
    virtual int getVisibility();
    virtual void receiveDamage(int power);

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;
};


#endif