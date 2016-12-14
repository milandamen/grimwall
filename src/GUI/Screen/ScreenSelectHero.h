//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_SELECTHERO_H
#define GRIMWALL_SELECTHERO_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"
#include "../../Domain/Units/Heroes/Dralas.h"
#include "../../Domain/Units/Heroes/Zarrku.h"

class ScreenSelectHero : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

public:
    ScreenSelectHero(IGame* game, AGUIManager* manager);
    ~ScreenSelectHero();
};


#endif //GRIMWALL_SELECTHERO_H
