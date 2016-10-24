#ifndef GRIMWALL_DRALAS_H
#define GRIMWALL_DRALAS_H

#include <iostream>
#include "./AHero.h"

class Dralas : public AHero {

public:
    Dralas();
    ~Dralas();

    void doDamage(int power) override;
};


#endif //GRIMWALL_DRALAS_H
