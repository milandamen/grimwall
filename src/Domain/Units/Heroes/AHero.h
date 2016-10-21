//
// Created by joost on 10/21/16.
//

#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include "../AUnit.h"

class AHero : AUnit {
private:
    virtual std::string name;
    virtual std::string weapon;
    virtual int reach;
    virtual int moveSpeed;
    virtual int attackDelay;
    virtual int power;
    virtual int hitPoints;
public:
    AHero(std::string name, std::string weapon, int reach, int moveSpeed, int attackDelay, int power, int hitPoints);
    AHero();
    ~AHero();
    virtual std::string getName() = 0;
    virtual std::string getWeapon() = 0;
    virtual int getReach() = 0;
    virtual int getMoveSpeed() = 0;
    virtual int getAttackDelay() = 0;
    virtual int getPower() = 0;
    virtual int getHitPoints() = 0;
};

#endif //GRIMWALL_AHERO_H
