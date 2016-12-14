//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_OPTIONS_H
#define GRIMWALL_OPTIONS_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenOptions : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

public:
    ScreenOptions(IGame* game, AGUIManager* manager);
    ~ScreenOptions();
};


#endif //GRIMWALL_OPTIONS_H
