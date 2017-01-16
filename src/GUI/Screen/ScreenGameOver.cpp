
#include "ScreenGameOver.h"

ScreenGameOver::ScreenGameOver(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{

    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    //this->imgGameOver = manager->addImage("assets/gui/exitMenuItem.png", 140, 300, 680, 100);

    this->btnExit = manager->addImageButton("", "assets/gui/exitMenuItem.png", 140, 550, 680, 100);
    this->btnExit->setForegroundColor(255, 255, 255, 255);
    this->btnExit->setBackgroundColor(0, 0, 0, 0);
    this->btnExit->onClick([&]() {
        game->quit();
    });
}

ScreenGameOver::~ScreenGameOver()
{
    delete this->imgBg;
    delete this->imgGameOver;
    delete this->btnExit;
}