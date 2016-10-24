//
// Created by roel on 21-10-16.
//

#ifndef GRIMWALL_DRALAS_H
#define GRIMWALL_DRALAS_H

#include <iostream>
#include "./AHero.h"

class Dralas : AHero {

public:
    Dralas() : AHero("Dralas", 3, 350, 7, 100, 200) {};
    ~Dralas();

    void doDamage(int power);
};


#endif //GRIMWALL_DRALAS_H
