#include "TowerFactory.h"


TowerFactory::TowerFactory()
{
    this->dictionary =
            {
                    {"defaultTower", [](){return new UnitManager<ATower>(new DefaultTower()); }},
                    {"rangedTower", [](){return new UnitManager<ATower>(new RangedTower()); }},
                    {"armouredTower", [](){return new UnitManager<ATower>(new ArmouredTower()); }},
            };
}

UnitManager<ATower>* TowerFactory::createTower(std::string name, double x, double y) {


    std::string key = name.substr(0, name.length()-1);
    auto tower = this->dictionary.find(key);

    if(tower != this->dictionary.end()) {
        //dictionary contains key
        UnitManager<ATower>* t  = tower->second();
        t->setX(x);
        t->setY(y);
        t->getBase()->setId(name);

        return t;
    }

    return nullptr;


}

