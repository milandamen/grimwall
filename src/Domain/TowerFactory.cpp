#include "TowerFactory.h"

void TowerFactory::populateDictionary() {
    //load
    this->dictionary.emplace("defaultTower", std::make_shared<DefaultTower>());
    this->dictionary.emplace("armouredTower", std::make_shared<ArmouredTower>());
    this->dictionary.emplace("rangedTower", std::make_shared<RangedTower>());

}

std::vector<std::shared_ptr<ATower>> TowerFactory::getTowers(std::vector<std::string> ids) {

    std::string key;
    std::vector<std::shared_ptr<ATower>> towerList;

    for (auto it = ids.begin(); it != ids.end(); ++it)
    {
        key = it->substr(0, it->length());
        auto tower = this->dictionary.find(key);

        if(tower != this->dictionary.end())
        {
            //dictionary contains key
            ATower t {*tower->second};
            std::shared_ptr g {std::make_shared(t)};
//            towerList.emplace(g);
        }
    }



    return towerList;
}

std::shared_ptr<ATower> TowerFactory::getTower(std::string id) {
    return std::shared_ptr<ATower>();
}
