
#ifndef GRIMWALL_SELECTLEVEL_H
#define GRIMWALL_SELECTLEVEL_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"
#include "../../Domain/UnitFactory.h"

class ScreenSelectLevel : public GUI {
private:
    IGame* game;
    AGUIManager* manager;
    FIFE::ModelCoordinate spawnPos;
public:
    ScreenSelectLevel(IGame* game, AGUIManager* manager);
    ~ScreenSelectLevel();
};


#endif //GRIMWALL_SELECTLEVEL_H
