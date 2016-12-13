//
// Created by stephanromer on 11/23/16.
//

#ifndef GRIMWALL_MAINMENU_H
#define GRIMWALL_MAINMENU_H


#include <fifechan.hpp>
#include <gui/fifechan/fifechanmanager.h>
#include "GUI.h"
#include "AGUIManager.h"
#include "../Domain/IGame.h"

class MainMenu : public GUI
{
private:
    IGame* game;
    AGUIManager* manager;

public:
    MainMenu(IGame* game, AGUIManager* manager);
    ~MainMenu();
};


#endif //GRIMWALL_MAINMENU_H
