#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include <vector>
#include "../AUnit.h"
#include "AAbility.h"

using namespace std;

class AHero : public AUnit {
protected:
    std::string weapon;
    int moveSpeed;
    int originalHitPoints;
        
public:
    AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints);
    ~AHero();
    std::string getWeapon();
    int getMoveSpeed();
    virtual void doDamage(int power);
};

#endif //GRIMWALL_AHERO_H
