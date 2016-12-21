
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>
#include "IUnit.h"

class AUnit : public IUnit {
protected:
    std::string name;
    double reach;
    int attackDelay;
    int power;
    int hitPoints;
    double speed;
    int visibility;

    double x{0};
    double y{0};

    int timeLastAttack {0};
public:
    AUnit(std::string name, double reach, int attackDelay, int power, int hitPoints, double speed,
    int visibility);
    ~AUnit();

    virtual std::string getName();
    virtual double getReach();
    virtual int getAttackDelay();
    virtual int getPower();
    virtual int getHitPoints();
    virtual double getSpeed();
    virtual int getVisibility();
    virtual void receiveDamage(int power);

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;

    void setTimeLastAttack(int time);
    int getTimeLastAttack();
};


#endif