#include "TowerFactory.h"

std::vector<UnitManager<ATower>*> generateTowers(std::vector<std::string> ids) {

    std::string key;
    std::string id;
    std::vector<UnitManager<ATower>*> towerList;

    static std::map<std::string, std::function<UnitManager<ATower>*()>> dictionary =
            {
                    {"defaultTower", [](){return new UnitManager<ATower>(new DefaultTower()); }},
                    {"rangedTower", [](){return new UnitManager<ATower>(new RangedTower()); }},
                    {"armouredTower", [](){return new UnitManager<ATower>(new ArmouredTower()); }},
            };

//    UnitManager<ATower> a;
//    a.getBase();

    for (auto it = ids.begin(); it != ids.end(); ++it)
    {
        id = *it;
        key = it->substr(0, it->length()-1);
        auto tower = dictionary.find(key);

        if(tower != dictionary.end())
        {
            //dictionary contains key
            UnitManager<ATower>* t  = tower->second();
            t->getBase()->setId(*it);

            towerList.emplace_back(t);
        }
    }



    return towerList;
}


