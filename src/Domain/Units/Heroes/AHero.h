#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include "../AUnit.h"

class AHero : AUnit {
private:
    std::string weapon;
    int moveSpeed;
public:
    AHero(std::string name, std::string weapon, int reach, int moveSpeed, int attackDelay, int power, int hitPoints);
    AHero();
    ~AHero();
    virtual std::string getWeapon() = 0;
    virtual int getMoveSpeed() = 0;
};

#endif //GRIMWALL_AHERO_H
