#ifndef GRIMWALL_TROUPMANAGER_H
#define GRIMWALL_TROUPMANAGER_H

#include <vector>
#include "ATroup.h"


class TroupManager {

private:
    std::vector<ATroup*> troups;
public:
    TroupManager();
    ~TroupManager();
    std::vector<ATroup*>* getTroups();
    void moveTroups(double x, double y);


};


#endif //GRIMWALL_TROUPMANAGER_H
