
#ifndef GRIMWALL_GAME_H
#define GRIMWALL_GAME_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenGame : public GUI {
private:
    IGame* game {nullptr};
    AGUIManager* manager {nullptr};

    GUIWidgetContainer* container {nullptr};

    void quitGame();

public:
    ScreenGame(IGame* game, AGUIManager* manager);
    ~ScreenGame();
};


#endif //GRIMWALL_GAME_H
