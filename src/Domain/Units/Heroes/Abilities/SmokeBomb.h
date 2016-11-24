#ifndef GRIMWALL_SMOKEBOMB_H
#define GRIMWALL_SMOKEBOMB_H


#include <vector>
#include "../AAbility.h"
#include "../../IUnit.h"

class SmokeBomb : AAbility{

private:
    std::vector<IUnit*> towers;

public:
    SmokeBomb(std::vector<IUnit*> towers);

    int execute();
};


#endif //GRIMWALL_SMOKEBOMB_H