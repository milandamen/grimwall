#include "TowerFactory.h"

UnitManager<ATower>* generateTower(std::string name, double x, double y) {

    static std::map<std::string, std::function<UnitManager<ATower>*()>> dictionary =
            {
                    {"defaultTower", [](){return new UnitManager<ATower>(new DefaultTower()); }},
                    {"rangedTower", [](){return new UnitManager<ATower>(new RangedTower()); }},
                    {"armouredTower", [](){return new UnitManager<ATower>(new ArmouredTower()); }},
            };


    std::string key = name.substr(0, name.length()-1);
    auto tower = dictionary.find(key);

    if(tower != dictionary.end())
    {
        //dictionary contains key
        UnitManager<ATower>* t  = tower->second();
        t->setX(x);
        t->setY(y);
        t->getBase()->setId(name);

        return t;
    } else
        return nullptr;
}


