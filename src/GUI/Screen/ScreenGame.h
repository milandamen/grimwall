//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_GAME_H
#define GRIMWALL_GAME_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenGame : public GUI {
private:
    IGame* game {nullptr};
    AGUIManager* manager {nullptr};

    GUIWidgetButton* rightMenu {nullptr};
    GUIWidgetContainer* rightMenuContainer {nullptr};
    GUIWidgetButton* rightMenuBtnSettings {nullptr};
    GUIWidgetButton* rightMenuBtnQuit {nullptr};
    GUIWidgetButton* rightMenuBtnPause {nullptr};

    void toggleRightMenu();
    void togglePauseGame();
    void showOptions();
    void quitGame();

public:
    ScreenGame(IGame* game, AGUIManager* manager);
    ~ScreenGame();
};


#endif //GRIMWALL_GAME_H
