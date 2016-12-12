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

std::vector<UnitManager<ATower>*> getTowers(std::vector<std::string> ids);

//class TowerFactory {
//private:
//    std::map<std::string, const std::shared_ptr<ATower>> dictionary;
//    void populateDictionary();
//public:
//
//    std::shared_ptr<ATower> getTower(std::string id);
//};


#endif //GRIMWALL_TOWERFACTORY_H
