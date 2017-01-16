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

    std::function<void()> updateStatsListener = [](){};
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
    void setInvincible(bool invincible);

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

    void setNext(IUnit *next);
    void setPrevious(IUnit *previous);

    bool attack() override;

    bool canAttack() override;

    void tick() override ;

    void setStatsListener(std::function<void()> delegate) override;
};


#endif //GRIMWALL_UNITDECORATOR_H
