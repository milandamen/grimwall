//
// Created by stephanromer on 1/16/17.
//

#include "ScreenHelp.h"

ScreenHelp::ScreenHelp(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{

    this->imgBg = manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    this->imgHelp = manager->addImage("assets/gui/exitMenuItem.png", 140, 300, 680, 100);

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 130, 550, 680, 100);
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