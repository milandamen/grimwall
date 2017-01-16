

#ifndef GRIMWALL_SCREENLOADING_H
#define GRIMWALL_SCREENLOADING_H


#include "../AGUIManager.h"
#include "../GUI.h"
#include "../../Domain/IGame.h"

class ScreenLoading : public GUI {
private:
    IGame* game;

    int duration{100};
    int timer{0};

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetContainer* progressBar {nullptr};
public:
    ScreenLoading(IGame* game, AGUIManager* manager);
    ~ScreenLoading();

    void hasBecomeActive() override;
    bool tick();
};


#endif //GRIMWALL_SCREENLOADING_H
