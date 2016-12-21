#include "TroupManager.h"

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
    for(unsigned i = 0; i < troups.size(); ++i){
        delete troups.at(i);
    }
    troups.clear();
}

std::vector<UnitManager<ATroup>*>* TroupManager::getTroups(){
    return &troups;
}

void TroupManager::moveTroups(double x, double y) {
    for(unsigned i = 0; i < troups.size(); ++i) {
        EngineFacade::engine()->move(
                troups.at(i)->getName(),
                "unitLayer",
                x,
                y,
                troups.at(i)->getSpeed()
        );
    }
}



void TroupManager::createSwordsman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Swordsman(
                    "" +
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createCrossbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Crossbowman(
                    "" +
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createLongbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Longbowman(
                    "" +
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createHorseman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Horseman(
                    "" +
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createCatapult(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Catapult(
                    "" +
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}
