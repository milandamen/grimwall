#include "TroupManager.h"

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
    for(unsigned i = 0; i < troups->size(); ++i){
        delete troups->at(i);
    }
    troups->clear();
    delete troups;
}

std::vector<ATroup*>* TroupManager::getTroups(){
    return troups;
}

void TroupManager::moveTroups(double x, double y) {
    // EngineFacade::move("basicTroup", x, y);
}

void TroupManager::createTroup(
        std::string objectName,
        std::string instanceName,
        double x,
        double y
) {
    EngineFacade::engine()->createInstance(
            objectName,
            instanceName,
            x,
            y
    );

    //troups.push_back()
}
