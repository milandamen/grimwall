#ifndef GRIMWALL_TOWERMANAGER_H
#define GRIMWALL_TOWERMANAGER_H

#include <vector>
#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"
#include "Units/Heroes/AHero.h"
#include "Units/Troups/ATroup.h"
#include <math.h>
#include <iostream>
#include <random>
#include <tgmath.h>
#include "UnitFactory.h"
#include "EngineFacade.h"

class TowerManager {

private:
    std::vector<UnitManager<ATower>*>* towers;
    std::vector<UnitManager<ATroup>*>* friendlyUnits;
    UnitManager<AHero>* hero {nullptr};
    bool speedHackEnabled {false};
    int speedHackLastTick {};
    std::random_device rd;
public:
    TowerManager();

    void tick();

    void setTowers(std::vector<UnitManager<ATower>*>* towers);
    void setUnits(std::vector<UnitManager<ATroup>*>* friendlyUnits);
    void setHero(UnitManager<AHero>* hero);
    void setSpeedHack(bool enabled);
};


#endif //GRIMWALL_TOWERMANAGER_H
