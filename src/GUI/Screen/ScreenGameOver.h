//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_GAMEOVER_H
#define GRIMWALL_GAMEOVER_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"


class ScreenGameOver : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

public:
    ScreenGameOver(IGame* game, AGUIManager* manager);
    ~ScreenGameOver();
};


#endif //GRIMWALL_GAMEOVER_H
