
#include "ScreenSelectLevel.h"


ScreenSelectLevel::ScreenSelectLevel(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    //manager->addImage("assets/gui/menuBackground.png", 0, 0, 1024, 768);
//    this->btnStart = manager->addButton("Start", 385, 182);
//
//    bh->onClick([&]() {
//        this->game->loadLevel("level1");
//        this->game->setPaused(false);
//        this->game->setUI("Game");
//    });
}

ScreenSelectLevel::~ScreenSelectLevel()
{
//    delete this->imgBg;
}