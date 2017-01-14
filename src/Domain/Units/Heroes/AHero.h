#ifndef GRIMWALL_AHERO_H
#define GRIMWALL_AHERO_H

#include <iostream>
#include <vector>
#include "../AUnit.h"
#include "AAbility.h"

class AHero : public AUnit {
protected:
    int mana = 100;
    int manaRegenTimeout = 60;
    bool infMana {false};

    std::string weapon;
    std::vector<AAbility*> abilities;
public:
    AHero(std::string name, int reach, int attackDelay, int moveSpeed, int power, int hitPoints, int visibility);
    ~AHero();
    std::string getWeapon();
    bool executeAbility(unsigned int number);
    void addAbility(AAbility* ability);

    int getMana();
    void setInfMana(bool infMana);

    void tick() override;
};

#endif //GRIMWALL_AHERO_H
