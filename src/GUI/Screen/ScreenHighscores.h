//
// Created by stephanromer on 1/16/17.
//

#ifndef GRIMWALL_SCREENHIGHSCORES_H
#define GRIMWALL_SCREENHIGHSCORES_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenHighscores : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgHelp {nullptr};
    GUIWidgetImageButton* btnReturn {nullptr};

public:
    ScreenHighscores(IGame* game, AGUIManager* manager);
    ~ScreenHighscores();
};


#endif //GRIMWALL_SCREENHIGHSCORES_H
