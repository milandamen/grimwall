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

void TroupManager::setTarget(UnitManager<ATower>* target){
    for(unsigned i = 0; i < selectedTroups.size(); ++i){
        selectedTroups.at(i)->getBase()->target = target;
    }
}

UnitManager<ATower>* TroupManager::getTarget(){
    return this->target;
}

void TroupManager::targetEnemy(double x, double y, std::vector<UnitManager<ATower> *> *targets) {
    bool targetAccuired = false;
    std::cout << "Accuiring target " << selectionDistance << " around click position (" << x << "," << y << ")" << std::endl;
    for(unsigned i = 0; i < targets->size(); ++i) {
        //Find the target that has been clicked on
        if(targets->at(i)->getX() >= (x - selectionDistance)
           && targets->at(i)->getX() <= (x + selectionDistance)
           && targets->at(i)->getY() >= (y - selectionDistance)
           && targets->at(i)->getY() <= (y + selectionDistance))
        {
            //Set the current target to the clicked target
            setTarget(targets->at(i));
            targetAccuired = true;
            std::cout << "Current Target: " << this->getTarget()->getName() << std::endl;
        }
    }
    //If no target is found on the clicked location, remove the target
    if(!targetAccuired){
        setTarget(nullptr);
        std::cout << "Current Target: none" << std::endl;
    }
}

void TroupManager::attackTarget(){
    for(unsigned i = 0; i < troups.size(); ++i) {

    }
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
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createCrossbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Crossbowman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createLongbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Longbowman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createHorseman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Horseman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}

void TroupManager::createCatapult(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Catapult(
                    instanceName +
                    std::to_string(troups.size())
            ));
    EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y);
    troups.push_back(tempTroup);
}
