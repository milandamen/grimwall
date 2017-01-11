//
// Created by stephanromer on 12/21/16.
//

#include "ScreenPause.h"

ScreenPause::ScreenPause(IGame *game, AGUIManager *manager)
        : GUI(manager), game(game)
{
    GUIWidgetLabel* l = manager->addLabel("", 0, 0);
    l->setWidth(1024);
    l->setHeight(768);
    l->setForegroundColor(0,0,0,255);
    l->setBackgroundColor(0,0,0,200);

    manager->addImage("assets/ads/advert.png", 212, 50, 600, 70);
    GUIWidgetButton* ba = manager->addButton("", 212, 50);
    ba->setWidth(600);
    ba->setHeight(70);
    ba->setBackgroundColor(0, 0, 0, 0);
    ba->onClick([](){
        system("firefox https://www.linux.com/");
    });

    GUIWidgetButton* br = manager->addButton("", 172, 500);
    br->setWidth(600);
    br->setHeight(70);
    br->setForegroundColor(255, 255, 255, 255);
    br->setBackgroundColor(0, 0, 0, 255);
    br->onClick([&](){
        this->game->setPaused(false);
        this->game->setUI("Game");
    });
}

ScreenPause::~ScreenPause()
{}