//
// Created by stephanromer on 1/16/17.
//

#ifndef GRIMWALL_SCREENHELP_H
#define GRIMWALL_SCREENHELP_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"


class ScreenHelp : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgHelp {nullptr};
    GUIWidgetImageButton* btnReturn {nullptr};

public:
    ScreenHelp(IGame* game, AGUIManager* manager);
    ~ScreenHelp();
};


#endif //GRIMWALL_SCREENHELP_H
