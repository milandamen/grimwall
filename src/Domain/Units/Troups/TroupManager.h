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
    double selectionDistance = 2;
    std::vector<UnitManager<ATroup>*> troups;
    std::vector<UnitManager<ATroup>*> selectedTroups;
public:
    TroupManager();
    ~TroupManager();
    std::vector<UnitManager<ATroup>*>* getTroups();

    // Targeting methods
    UnitManager<ATower>* getTarget();
    void setTarget(UnitManager<ATower>*);
    void targetEnemy(double x, double y, std::vector<UnitManager<ATower>*>* targets);

    // Function methods
    void moveTroups(double x, double y);
    void attackTarget();

    // Create methods
    void createSwordsman(std::string instanceName, double x, double y);
    void createCrossbowman(std::string instanceName, double x, double y);
    void createLongbowman(std::string instanceName, double x, double y);
    void createHorseman(std::string instanceName, double x, double y);
    void createCatapult(std::string instanceName, double x, double y);

};


#endif
