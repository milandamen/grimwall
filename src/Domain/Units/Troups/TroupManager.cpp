#include "TroupManager.h"

TroupManager::TroupManager(){

}

TroupManager::~TroupManager(){
    for(unsigned i = 0; i < troups.size(); ++i){
        delete troups.at(i);
    }
    troups.clear();
    delete troups;
}

std::vector<ATroup*>* TroupManager::getTroups(){
    return &troups;
}

void TroupManager::moveTroups(double x, double y) {
    
}
