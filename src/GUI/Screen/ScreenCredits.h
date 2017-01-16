//
// Created by stephanromer on 1/16/17.
//

#ifndef GRIMWALL_SCREENCREDITS_H
#define GRIMWALL_SCREENCREDITS_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"


class ScreenCredits : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetButton* btnReturn {nullptr};

public:
    ScreenCredits(IGame* game, AGUIManager* manager);
    ~ScreenCredits();
};


#endif //GRIMWALL_SCREENCREDITS_H
