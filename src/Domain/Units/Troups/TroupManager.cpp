#include "TroupManager.h"

class Flit;

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
    selectedTroups.clear();
    for(unsigned i = 0; i < troups.size(); ++i){
        delete troups.at(i);
    }
    troups.clear();
}

void TroupManager::setTowers(std::vector<UnitManager<ATower>* >* towerlist){
    this->towers = towerlist;
}

std::vector<UnitManager<ATroup>*>* TroupManager::getTroups(){
    return &troups;
}

void TroupManager::setSelectionStart(double x, double y){
    this->sStartX = x;
    this->sStartY = y;
}

void TroupManager::setSelectionEnd(double x, double y){
    selectedTroups.clear();

    this->sEndX = x;
    this->sEndY = y;

    double upLeftx;
    double upLefty;
    double downRightx;
    double downRighty;

    double diff = (sEndY - sStartY) / 2;

    //upleft to downright
    upLeftx = sStartX - diff;
    upLefty = sStartY;
    downRightx = sEndX + diff;
    downRighty = sEndY;

    for(unsigned i = 0; i < troups.size(); ++i){
        if(troups.at(i)->getX() > upLeftx &&
           troups.at(i)->getX() < downRightx &&
           troups.at(i)->getY() > upLefty &&
           troups.at(i)->getY() < downRighty){
            selectedTroups.push_back(troups.at(i));
        }
    }

    this->sStartX = 0;
    this->sStartY = 0;
    this->sEndX = 0;
    this->sEndY = 0;
}

void TroupManager::setTarget(UnitManager<ATower>* target){
    for(unsigned i = 0; i < selectedTroups.size(); ++i){
        this->selectedTroups.at(i)->getBase()->target = target;
    }
}

void TroupManager::targetEnemy(double x, double y, std::vector<UnitManager<ATower> *> *targets) {
    bool targetAccuired = false;
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
        }
    }
    //If no target is found on the clicked location, remove the target
    if(!targetAccuired){
        setTarget(nullptr);
    }
}

void TroupManager::attackTarget(){
    for(unsigned i = 0; i < troups.size(); ++i) {
        if (troups.at(i)->getBase()->target != nullptr) {
            double deltaX{std::pow((troups.at(i)->getBase()->target->getX() - troups.at(i)->getX()), 2.0)};
            double deltaY{std::pow((troups.at(i)->getBase()->target->getY() - troups.at(i)->getY()), 2.0)};
            double distance{std::sqrt(deltaX + deltaY)};

            if (distance <= troups.at(i)->getReach()) {
                if(troups.at(i)->attack()) {
                    EngineFacade::engine()->setInstanceAction(troups.at(i)->getBase()->getName(), "attack", "unitLayer");
                    troups.at(i)->getBase()->target->receiveDamage(troups.at(i)->getPower());
                }
            }
        }
    }
}

void TroupManager::moveTroups(double x, double y) {
    for(unsigned i = 0; i < selectedTroups.size(); ++i) {
        EngineFacade::engine()->move(
                selectedTroups.at(i)->getBase()->getName(),
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
    if(EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y) != "ERROR"){
        troups.push_back(tempTroup);
    }
}

void TroupManager::createCrossbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Crossbowman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    if(EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y) != "ERROR"){
        troups.push_back(tempTroup);
    }
}

void TroupManager::createLongbowman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Longbowman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    if(EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y) != "ERROR"){
        troups.push_back(tempTroup);
    }
}

void TroupManager::createHorseman(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Horseman(
                    instanceName +
                    std::to_string(troups.size())
            ));
    if(EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y) != "ERROR"){
        troups.push_back(tempTroup);
    }
}

void TroupManager::createCatapult(std::string instanceName, double x, double y){
    UnitManager<ATroup>* tempTroup = new UnitManager<ATroup>(
            new Catapult(
                    instanceName +
                    std::to_string(troups.size())
            ));
    if(EngineFacade::engine()->createInstance(instanceName, instanceName + std::to_string(troups.size()), x, y) != "ERROR"){
        troups.push_back(tempTroup);
    }
}

void TroupManager::tick(){

    UnitManager<ATroup> *troup;
    for (std::vector<UnitManager<ATroup> *>::iterator it = troups.begin(); it != troups.end();) {
        troup = *it;
        if(troup->getHitPoints() <= 0){
            if (EngineFacade::engine()->instanceExists(troup->getBase()->getName(), "unitLayer")) {
                EngineFacade::engine()->deleteInstance(troup->getBase()->getName(), "unitLayer");
            }
            UnitManager<ATroup> *selTroup;
            for (std::vector<UnitManager<ATroup> *>::iterator its = selectedTroups.begin(); its != selectedTroups.end();) {
                selTroup = *its;
                if(selTroup->getBase()->getName() == troup->getBase()->getName()){
                    selectedTroups.erase(its);
                }
                ++its;
            }
            troups.erase(it);
            delete troup;
        }
        else {
            ++it;
        }
    }

    for(unsigned i = 0; i < troups.size(); ++i){
        troups.at(i)->tick();
    }
    attackTarget();

    UnitManager<ATower> *tower;
    for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end();) {
        tower = *it;
        if (tower->getHitPoints() <= 0) {
            if (EngineFacade::engine()->instanceExists(tower->getBase()->getId(), "towerLayer")) {
                EngineFacade::engine()->deleteInstance(tower->getBase()->getId(), "towerLayer");
            }
            for (unsigned i = 0; i < troups.size(); ++i) {
                if(troups.at(i)->getBase()->target != nullptr) {
                    if (troups.at(i)->getBase()->target->getBase()->getId() == tower->getBase()->getId()) {
                        troups.at(i)->getBase()->target = nullptr;
                    }
                }
            }
            towers->erase(it);
            delete tower;
        }
        else {
            ++it;
        }
    }
}

void TroupManager::reset(){
    selectedTroups.clear();
    troups.clear();
}
