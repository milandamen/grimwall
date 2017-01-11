#ifndef GRIMWALL_TROUPMANAGER_H
#define GRIMWALL_TROUPMANAGER_H

#include <vector>
#include "ATroup.h"
#include "Swordsman.h"
#include "Catapult.h"
#include "Crossbowman.h"
#include "Horseman.h"
#include "Longbowman.h"
#include "../../EngineFacade.h"

class TroupManager {

private:
    std::vector<UnitManager<ATroup>*> troups;
public:
    TroupManager();
    ~TroupManager();
    std::vector<UnitManager<ATroup>*>* getTroups();

    // Function methods
    void moveTroups(double x, double y);

    // Create methods
    void createSwordsman(std::string instanceName, double x, double y);
    void createCrossbowman(std::string instanceName, double x, double y);
    void createLongbowman(std::string instanceName, double x, double y);
    void createHorseman(std::string instanceName, double x, double y);
    void createCatapult(std::string instanceName, double x, double y);

};


#endif
