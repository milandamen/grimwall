
#include "ScreenGameOver.h"

ScreenGameOver::ScreenGameOver(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{

    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    this->imgGameOver = manager->addImage("assets/gui/gameOver.png", 112, 340, 120, 800);

    this->btnExit = manager->addImageButton("", "assets/gui/exitMenuItem.png", 172, 550, 680, 100);
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

void ScreenGameOver::hasBecomeActive() {
    EngineFacade::engine()->stopMusic();
    EngineFacade::engine()->playSoundEffect("gameOver");
}