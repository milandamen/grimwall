
#ifndef GRIMWALL_SELECTLEVEL_H
#define GRIMWALL_SELECTLEVEL_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"
#include "../../Domain/UnitFactory.h"

#include <vector>

class ScreenSelectLevel : public GUI {
private:
    IGame* game;
    AGUIManager* manager;
public:
    ScreenSelectLevel(IGame* game, AGUIManager* manager);
    ~ScreenSelectLevel();
};


#endif //GRIMWALL_SELECTLEVEL_H
