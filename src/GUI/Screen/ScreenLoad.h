#ifndef GRIMWALL_SCREENLOAD_H
#define GRIMWALL_SCREENLOAD_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"
#include "../../Domain/SaveGame/SaveGameManager.h"

class ScreenLoad : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};

    GUIWidgetImageButton* gameSlot1 {nullptr};
    GUIWidgetImageButton* gameSlot2 {nullptr};
    GUIWidgetImageButton* gameSlot3 {nullptr};

    GUIWidgetLabel* loadSave {nullptr};

    GUIWidgetImageButton* btnReturn {nullptr};

public:
    ScreenLoad(IGame* game, AGUIManager* manager);
    ~ScreenLoad();
};

#endif //GRIMWALL_SCREENLOAD_H
