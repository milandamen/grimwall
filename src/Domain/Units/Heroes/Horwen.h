//
// Created by baksteen on 10/24/16.
//

#ifndef GRIMWALL_HORWEN_H
#define GRIMWALL_HORWEN_H

#include <iostream>
#include <vector>
#include "AAbility.h"
#include "AHero.h"

using namespace std;

class Horwen: public AHero {


public:

    Horwen();
    ~Horwen();

    void activateRage();

    string getName() override;
    int getReach() override;
    int getAttackDelay() override;
    int getPower() override;
    int getHitPoints() override;
    int getOriginalHitPoints() override;

    void doDamage(int power) override;
};

#endif //GRIMWALL_HORWEN_H
