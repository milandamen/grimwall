
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
    GUIWidgetLabel* lblHeroName {nullptr};
    GUIWidgetLabel* lblHeroHP {nullptr};
    GUIWidgetLabel* lblHeroMP {nullptr};
    GUIWidgetContainer* pgbHeroHP {nullptr};
    GUIWidgetContainer* pgbHeroMP {nullptr};
    GUIWidgetButton* btnPause {nullptr};

    GUIWidgetLabel* lblAbilitie1Name {nullptr};
    GUIWidgetLabel* lblAbilitie1Key {nullptr};
    GUIWidgetLabel* lblAbilitie2Name {nullptr};
    GUIWidgetLabel* lblAbilitie2Key {nullptr};
    GUIWidgetLabel* lblAbilitie3Name {nullptr};
    GUIWidgetLabel* lblAbilitie3Key {nullptr};
    GUIWidgetLabel* lblAbilitie4Name {nullptr};
    GUIWidgetLabel* lblAbilitie4Key {nullptr};

    std::vector<GUIWidgetLabel*> lblBuffs;

    void deleteBuffs();

    void updateStats();
    void quitGame();
    void pause();

    void hasBecomeActive() override;
    void hasBecomeInactive() override;

public:
    ScreenGame(IGame* game, AGUIManager* manager);
    ~ScreenGame();
};


#endif //GRIMWALL_GAME_H
