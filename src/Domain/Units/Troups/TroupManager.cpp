#include "TroupManager.h"

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
    for(unsigned i = 0; i < troups.size(); ++i){
        delete troups.at(i);
    }
    troups.clear();
}

std::vector<ATroup*> TroupManager::getTroups(){
    return troups;
}

void TroupManager::moveTroups(double x, double y) {
    for(unsigned i = 0; i < troups.size(); ++i) {
        EngineFacade::engine()->move(troups.at(i)->getName(), "unitLayer", x, y, troups.at(i)->getSpeed());
    }
}

void TroupManager::createTroup(std::string instanceName, double x, double y){
    ATroup* tempTroop {new Swordsman("" + instanceName + std::to_string(troups.size()))};
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroop);
}
