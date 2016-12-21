#ifndef GRIMWALL_TOWERFACTORY_H
#define GRIMWALL_TOWERFACTORY_H


#include <vector>
#include "Units/Towers/ATower.h"
#include <memory>
#include <map>
#include "Units/Towers/DefaultTower.h"
#include "Units/Towers/ArmouredTower.h"
#include "Units/Towers/RangedTower.h"
#include "Units/UnitManager.hpp"


class TowerFactory{

private:
    std::map<std::string, std::function<UnitManager<ATower>*()>> dictionary;

public:
    UnitManager<ATower>* createTower(std::string name, double x, double y);
    TowerFactory();
};

#endif //GRIMWALL_TOWERFACTORY_H
