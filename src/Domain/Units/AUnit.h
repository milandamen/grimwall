
#ifndef GRIMWALL_AUNIT_H
#define GRIMWALL_AUNIT_H

#include <iostream>
#include "IUnit.h"

class AUnit : public IUnit {
protected:
    IUnit *previous;

    std::string name;
    double reach;
    int attackDelay;
    int power;
    int hitPoints;
    bool invincible {false};
    double speed;
    int visibility;

    double x{0};
    double y{0};

    int attackWait{0};

    std::function<void()> updateStatsListener = [](){};
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
    virtual void setInvincible(bool invincible);
    virtual std::vector<std::string> getBuffs();
    virtual void setInvisible(bool invisible);

    double getX() override;
    void setX(double x) override;
    double getY() override;
    void setY(double y) override;
    
    void setNext(IUnit *next);
    void setPrevious(IUnit *previous);

    bool attack() override;
    bool canAttack() override;

    virtual void tick() override;
    void setStatsListener(std::function<void()> delegate) override;
};


#endif