
#ifndef GRIMWALL_GAMEOVER_H
#define GRIMWALL_GAMEOVER_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"


class ScreenGameOver : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgGameOver {nullptr};
    GUIWidgetImageButton* btnExit {nullptr};

    void hasBecomeActive() override;

public:
    ScreenGameOver(IGame* game, AGUIManager* manager);
    ~ScreenGameOver();
};


#endif //GRIMWALL_GAMEOVER_H
