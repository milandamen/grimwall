#ifndef GRIMWALL_TROUPMANAGER_H
#define GRIMWALL_TROUPMANAGER_H

#include <vector>
#include "ATroup.h"
#include "../../IGame.h"
#include "../../EngineFacade.h"


class TroupManager {

private:
    std::vector<ATroup*> troups;
public:
    TroupManager();
    ~TroupManager();
    std::vector<ATroup*>* getTroups();
    void moveTroups(double x, double y);
    void createTroup(std::string objectName,
                     std::string instanceName,
                     double x,
                     double y);

};


#endif
