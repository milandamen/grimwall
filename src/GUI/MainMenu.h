//
// Created by stephanromer on 11/23/16.
//

#ifndef GRIMWALL_MAINMENU_H
#define GRIMWALL_MAINMENU_H


#include <fifechan.hpp>
#include <gui/fifechan/fifechanmanager.h>
#include "GUI.h"

class MainMenu : public GUI {

public:
    MainMenu(FIFE::FifechanManager* manager);
    ~MainMenu();

private:
    FIFE::FifechanManager* manager;
    //void action(const fcn::ActionEvent& actionEvent) override;
};


#endif //GRIMWALL_MAINMENU_H
