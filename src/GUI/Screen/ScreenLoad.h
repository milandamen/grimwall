#ifndef GRIMWALL_SCREENLOAD_H
#define GRIMWALL_SCREENLOAD_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenLoad : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};

    GUIWidgetButton* gameSlot1 {nullptr};
    GUIWidgetButton* gameSlot2 {nullptr};
    GUIWidgetButton* gameSlot3 {nullptr};

    GUIWidgetLabel* loadSave {nullptr};

    GUIWidgetImageButton* btnReturn {nullptr};



public:
    ScreenLoad(IGame* game, AGUIManager* manager);
    ~ScreenLoad();
};

#endif //GRIMWALL_SCREENLOAD_H
