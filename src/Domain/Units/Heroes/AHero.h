#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include "../AUnit.h"

class AHero : AUnit {
protected:
    std::string weapon;
    int moveSpeed;
public:
    AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints) : AUnit(name, reach, attackDelay, power, hitPoints){};
    ~AHero();
    virtual std::string getWeapon() = 0;
    virtual int getMoveSpeed() = 0;
    virtual void doDamage(int power);
};

#endif //GRIMWALL_AHERO_H
