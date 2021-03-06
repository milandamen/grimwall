
#ifndef GRIMWALL_WON_H
#define GRIMWALL_WON_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"


class ScreenWon : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgLevelCleared {nullptr};
    GUIWidgetImageButton* btnNext {nullptr};

    void hasBecomeActive() override;

public:
    ScreenWon(IGame* game, AGUIManager* manager);
    ~ScreenWon();
};


#endif //GRIMWALL_WON_H
