//
// Created by stephanromer on 12/14/16.
//

#include "ScreenOptions.h"

ScreenOptions::ScreenOptions(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);

    GUIWidgetLabel* l = manager->addLabel("Want to change some settings?", 140, 350);
    l->setWidth(300);
    l->setHeight(100);
    l->setBackgroundColor(0,0,0,128);
    l->setForegroundColor(255,0,0,128);

    GUIWidgetButton* b = manager->addButton("Back", 140, 550);
    b->setWidth(680);
    b->setHeight(100);
    //b->setForegroundColor(255, 255, 255, 255);
    //b->setBackgroundColor(0, 0, 0, 0);
    b->onClick([&]() {
        this->game->setUI("MainMenu");
    });

    GUIWidgetRadio* r1 = manager->addRadio("Aan", "music", 100, 100, true);
    GUIWidgetRadio* r2 = manager->addRadio("Uit", "music", 100, 120);
}

ScreenOptions::~ScreenOptions()
{}