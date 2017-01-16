#ifndef GRIMWALL_SCREENLOAD_H
#define GRIMWALL_SCREENLOAD_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenLoad : public GUI {
private:
IGame* game;
AGUIManager* manager;


public:
ScreenLoad(IGame* game, AGUIManager* manager);
~ScreenLoad();
};

#endif //GRIMWALL_SCREENLOAD_H
