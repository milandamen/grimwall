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

UnitManager<ATower>* generateTower(std::string name, double x, double y);

#endif //GRIMWALL_TOWERFACTORY_H
