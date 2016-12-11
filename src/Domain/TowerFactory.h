#ifndef GRIMWALL_TOWERFACTORY_H
#define GRIMWALL_TOWERFACTORY_H


#include <vector>
#include "Units/Towers/ATower.h"
#include <memory>
#include <map>
#include "Units/Towers/DefaultTower.h"
#include "Units/Towers/ArmouredTower.h"
#include "Units/Towers/RangedTower.h"

class TowerFactory {
private:
    std::map<std::string, const std::shared_ptr<ATower>> dictionary;
    void populateDictionary();
public:
    std::vector<std::shared_ptr<ATower>> getTowers(std::vector<std::string> ids);
    std::shared_ptr<ATower> getTower(std::string id);
};


#endif //GRIMWALL_TOWERFACTORY_H
