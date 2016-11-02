
#ifndef GRIMWALL_ZARRKU_H
#define GRIMWALL_ZARRKU_H

#include <iostream>
#include "AHero.h"

class Zarrku : public AHero{

private:

public:
    Zarrku();
//    ~Zarrku();
    void doDamage(int power) override;

};


#endif //GRIMWALL_ZARRKU_H
