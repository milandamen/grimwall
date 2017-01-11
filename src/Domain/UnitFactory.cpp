
#include "UnitFactory.h"
#include "EngineFacade.h"

void updateLocation(IUnit* unit, std::string name) {
    if (EngineFacade::engine()->instanceExists(name)) {
        unit->setX(EngineFacade::engine()->getInstanceX(name)+1);
        unit->setY(EngineFacade::engine()->getInstanceY(name)-1);
    }
}