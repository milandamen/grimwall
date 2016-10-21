#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include "../AUnit.h"

class AHero : AUnit {
private:
    std::string weapon;
    int moveSpeed;
public:
    virtual std::string getWeapon() = 0;
    virtual int getMoveSpeed() = 0;
};

#endif //GRIMWALL_AHERO_H
