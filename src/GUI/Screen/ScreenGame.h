
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
    GUIWidgetLabel* lbl_hero_name {nullptr};
    GUIWidgetLabel* lbl_hero_hp {nullptr};
    GUIWidgetLabel* lbl_hero_mp {nullptr};
    GUIWidgetContainer* pgb_hero_hp {nullptr};
    GUIWidgetContainer* pgb_hero_mp {nullptr};

    void updateStats();
    void quitGame();

    void hasBecomeActive() override;
    void hasBecomeInactive() override;

public:
    ScreenGame(IGame* game, AGUIManager* manager);
    ~ScreenGame();
};


#endif //GRIMWALL_GAME_H
