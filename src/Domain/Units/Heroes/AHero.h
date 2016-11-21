#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include "../AUnit.h"

class AHero : public AUnit {
protected:
    std::string weapon;
public:
    AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility);
    ~AHero();
    std::string getWeapon();
    virtual void doDamage(int power);
};

#endif //GRIMWALL_AHERO_H
