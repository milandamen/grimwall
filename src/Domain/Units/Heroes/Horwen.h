//
// Created by baksteen on 10/24/16.
//

#ifndef GRIMWALL_HORWEN_H
#define GRIMWALL_HORWEN_H

#include <iostream>
#include "./AHero.h"

class Horwen: public AHero {

public:

    Horwen();
    ~Horwen();

    void activateRage();

    void doDamage(int power) override;
};

#endif //GRIMWALL_HORWEN_H
