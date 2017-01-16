//
// Created by stephanromer on 1/16/17.
//

#include "ScreenCredits.h"

ScreenCredits::ScreenCredits(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/backgroundCredits.png", 0, 0, 1024, 786);

    this->btnReturn = manager->addButton("", 0, 0);
    this->btnReturn->setWidth(1024);
    this->btnReturn->setHeight(768);
    this->btnReturn->setForegroundColor(255, 255, 255, 0);
    this->btnReturn->setBackgroundColor(0, 0, 0, 0);
    this->btnReturn->onClick([&]() {
        this->game->setUI("MainMenu");
    });
}

ScreenCredits::~ScreenCredits()
{
    delete this->imgBg;
    delete this->btnReturn;
}