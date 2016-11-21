//
// Created by baksteen on 10/24/16.
//

#ifndef GRIMWALL_HORWEN_H
#define GRIMWALL_HORWEN_H

#include <iostream>
#include <vector>
#include "./AHero.h"
#include "AAbility.h"

class Horwen: public AHero {

private:
    std::vector<AAbility*> abilities;
    

public:
    Horwen();
    ~Horwen();

    void doDamage(int power) override;
};

#endif //GRIMWALL_HORWEN_H
