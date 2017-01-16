#include "TroupManager.h"

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
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
    std::cout << "Selection started.." << std::endl;
}

void TroupManager::setSelectionEnd(double x, double y){
    selectedTroups.clear();

    this->sEndX = x;
    this->sEndY = y;
    std::cout << "Selection ended." << std::endl;

    double upLeftx;
    double upLefty;
    double downRightx;
    double downRighty;

    //upleft to downright
    upLeftx = sStartX;
    upLefty = sStartY;
    downRightx = sEndX;
    downRighty = sEndY;

    std::cout << "selecting troups between " << upLeftx << "," << upLefty << " and " << downRightx << "," << downRighty << std::endl;


    for(unsigned i = 0; i < troups.size(); i++){
        std::cout << "Troup at " << troups.at(i)->getX() << "," << troups.at(i)->getY() << std::endl;
        if(troups.at(i)->getX() > upLeftx &&
           troups.at(i)->getX() < downRightx &&
           troups.at(i)->getY() > upLefty &&
           troups.at(i)->getY() < downRighty){
            selectedTroups.push_back(troups.at(i));
            std::cout << "selected " << troups.at(i)->getName() << std::endl;
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
            std::cout << "Current Target: " << targets->at(i)->getName() << std::endl;
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
        if (troups.at(i)->getBase()->target != nullptr) {
            double deltaX{std::pow((troups.at(i)->getBase()->target->getX() - troups.at(i)->getX()), 2.0)};
            double deltaY{std::pow((troups.at(i)->getBase()->target->getY() - troups.at(i)->getY()), 2.0)};
            double distance{std::sqrt(deltaX + deltaY)};

            if (distance <= troups.at(i)->getReach()) {
                if(troups.at(i)->attack()) {
                    std::cout << "Attacked! Tower health: " << troups.at(i)->getBase()->target->getHitPoints()
                              << std::endl;
                    troups.at(i)->getBase()->target->receiveDamage(troups.at(i)->getPower());

                    if (troups.at(i)->getBase()->target->getHitPoints() <= 0) {
                        if (EngineFacade::engine()->instanceExists(troups.at(i)->getBase()->target->getBase()->getId(),
                                                                   "towerLayer")) {
                            EngineFacade::engine()->deleteInstance(troups.at(i)->getBase()->target->getBase()->getId(),
                                                                   "towerLayer");
                        }

                        UnitManager<ATower> *tower;
                        for (std::vector<UnitManager<ATower> *>::iterator it = towers->begin(); it != towers->end();) {
                            tower = *it;
                            if (tower->getBase()->getId() == troups.at(i)->getBase()->target->getBase()->getId()){
                                for(unsigned b = 0; b < troups.size(); ++b) {
                                    if(troups.at(b)->getBase()->target != nullptr) {
                                        if (troups.at(b)->getBase()->target->getBase()->getId() ==
                                            tower->getBase()->getId()) {
                                            troups.at(b)->getBase()->target = nullptr;
                                        }
                                    }
                                }
                                delete tower;
                                towers->erase(it);
                                return;
                            }
                            else {
                                ++it;
                            }
                        }
                    }
                }
            }
        }
    }
}

void TroupManager::moveTroups(double x, double y) {

    for(unsigned i = 0; i < selectedTroups.size(); ++i) {
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
    for(unsigned i = 0; i < troups.size(); ++i){
        troups.at(i)->tick();
    }
    attackTarget();
}
