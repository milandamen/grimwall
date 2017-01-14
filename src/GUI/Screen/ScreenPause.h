//
// Created by stephanromer on 12/21/16.
//

#ifndef GRIMWALL_SCREENPAUSE_H
#define GRIMWALL_SCREENPAUSE_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenPause : public GUI {

private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetContainer * fog {nullptr};
    GUIWidgetImageButton* btnAd {nullptr};
    GUIWidgetImageButton* btnReturn {nullptr};

public:
    ScreenPause(IGame* game, AGUIManager* manager);
    ~ScreenPause();
};


#endif //GRIMWALL_SCREENPAUSE_H
