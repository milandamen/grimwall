
#ifndef GRIMWALL_SCREENHIGHSCORES_H
#define GRIMWALL_SCREENHIGHSCORES_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenHighscores : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    bool loaded {false};

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgHelp {nullptr};
    GUIWidgetImageButton* btnReturn {nullptr};

    GUIWidgetLabel* lblSlot1 {nullptr};
    GUIWidgetLabel* lblSlot2 {nullptr};
    GUIWidgetLabel* lblSlot3 {nullptr};

    void hasBecomeActive() override;

public:
    ScreenHighscores(IGame* game, AGUIManager* manager);
    ~ScreenHighscores();
};


#endif //GRIMWALL_SCREENHIGHSCORES_H
