#ifndef GRIMWALL_BOMB_H
#define GRIMWALL_BOMB_H

#include "../AAbility.h"
#include "../AHero.h"
#include "../../UnitManager.hpp"
#include "../../Towers/ATower.h"

class Bomb : public AAbility{

private:
    UnitManager<AHero>* hero;
    std::vector<UnitManager<ATower> *>* towers;
public:
    Bomb(UnitManager<AHero>* hero, std::vector<UnitManager<ATower> *>* towers);
    int execute();
};


#endif //GRIMWALL_BOMB_H
