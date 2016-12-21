
#ifndef GRIMWALL_MAINMENU_H
#define GRIMWALL_MAINMENU_H


#include <fifechan.hpp>
#include <gui/fifechan/fifechanmanager.h>
#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenMainMenu : public GUI
{
private:
    IGame* game;
    AGUIManager* manager;

public:
    ScreenMainMenu(IGame* game, AGUIManager* manager);
    ~ScreenMainMenu();
};


#endif //GRIMWALL_MAINMENU_H
