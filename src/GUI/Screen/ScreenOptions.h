
#ifndef GRIMWALL_OPTIONS_H
#define GRIMWALL_OPTIONS_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"

class ScreenOptions : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgMusic {nullptr};
    GUIWidgetImageButton* stnMusic {nullptr};
    GUIWidgetImage* imgSFX {nullptr};
    GUIWidgetImageButton* stnSFX {nullptr};
    GUIWidgetImageButton* btnReturn {nullptr};

public:
    ScreenOptions(IGame* game, AGUIManager* manager);
    ~ScreenOptions();
};


#endif //GRIMWALL_OPTIONS_H
