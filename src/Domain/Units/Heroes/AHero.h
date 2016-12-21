#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include <vector>
#include "../AUnit.h"
#include "AAbility.h"

class AHero : public AUnit {
protected:
    std::string weapon;
    std::vector<AAbility*> abilities;
public:
    AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility);
    ~AHero();
    std::string getWeapon();
    void executeAbility(int number);
    void addAbility(AAbility* ability);
};

#endif //GRIMWALL_AHERO_H
