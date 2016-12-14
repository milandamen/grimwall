//
// Created by stephanromer on 12/14/16.
//

#include "ScreenSelectLevel.h"

ScreenSelectLevel::ScreenSelectLevel(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    GUIWidgetButton* bh = manager->addButton("Level 1", 385, 182);
    bh->setWidth(285);
    bh->setHeight(556);
    //bh->setForegroundColor(255, 255, 255, 255);
    //bh->setBackgroundColor(0, 0, 0, 0);
    bh->onClick([&]() {
        this->game->setMap("assets/maps/level1_remake_conv.xml");
        this->game->setPaused(false);
        this->game->setUI("Game");
    });
}

ScreenSelectLevel::~ScreenSelectLevel()
{}