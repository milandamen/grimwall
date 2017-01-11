#ifndef GRIMWALL_TOWERMANAGER_H
#define GRIMWALL_TOWERMANAGER_H

#include <vector>
#include "Units/UnitManager.hpp"
#include "Units/Towers/ATower.h"
#include "Units/Heroes/AHero.h"
#include <math.h>

class TowerManager {

private:
    std::vector<UnitManager<ATower>*>* towers;
    std::vector<UnitManager<AUnit>*> friendlyUnits;
    UnitManager<AHero>* hero {nullptr};
public:
    TowerManager();

    void tick(int curTime);

    void setTowers(std::vector<UnitManager<ATower>*>* towers);
    void setUnits(std::vector<UnitManager<AUnit>*> friendlyUnits);
    void setHero(UnitManager<AHero>* hero);

};


#endif //GRIMWALL_TOWERMANAGER_H
