
#ifndef GRIMWALL_SELECTHERO_H
#define GRIMWALL_SELECTHERO_H

#include "../GUI.h"
#include "../AGUIManager.h"
#include "../../Domain/IGame.h"
#include "../../Domain/Units/Heroes/Dralas.h"
#include "../../Domain/Units/Heroes/Zarrku.h"

class ScreenSelectHero : public GUI {
private:
    IGame* game;
    AGUIManager* manager;

    GUIWidgetImage* imgBg {nullptr};
    GUIWidgetImage* imgChooseYourHero {nullptr};
    GUIWidgetImageButton* btnDralas {nullptr};
    GUIWidgetImageButton* btnHorwen {nullptr};
    GUIWidgetImageButton* btnZarrku {nullptr};

public:
    ScreenSelectHero(IGame* game, AGUIManager* manager);
    ~ScreenSelectHero();
};


#endif //GRIMWALL_SELECTHERO_H
