//
// Created by stephanromer on 1/16/17.
//

#include "ScreenHelp.h"

ScreenHelp::ScreenHelp(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{

    this->imgBg = manager->addImage("assets/gui/backgroundHelp.png", 0, 0, 1024, 786);

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 172, 650, 680, 100);
    this->btnReturn->setForegroundColor(255, 255, 255, 255);
    this->btnReturn->setBackgroundColor(0, 0, 0, 0);
    this->btnReturn->onClick([&]() {
        this->game->setUI("Pause");
    });
}

ScreenHelp::~ScreenHelp()
{
    delete this->imgBg;
    delete this->imgHelp;
    delete this->btnReturn;
}