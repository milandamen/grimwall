
#include "ScreenWon.h"

ScreenWon::ScreenWon(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    this->imgLevelCleared = manager->addImage("assets/gui/levelCleared.png", 12, 340, 120, 1000);

    this->btnNext = manager->addImageButton("", "assets/gui/btnNextLevel.png", 212, 550, 600, 100);
    this->btnNext->setForegroundColor(255, 255, 255, 255);
    this->btnNext->setBackgroundColor(0, 0, 0, 0);
}

ScreenWon::~ScreenWon()
{
    delete this->imgBg;
    delete this->imgLevelCleared;
    delete this->btnNext;
}

void ScreenWon::hasBecomeActive()
{
    EngineFacade::engine()->playSoundEffect("finishLevel");
    std::string next = this->game->getCurrentLevel()->getNext();
    if(next == "") { // Last level reached!
        this->btnNext->setAsset("assets/gui/exitMenuItem.png");
        this->btnNext->setWidth(680);
        this->btnNext->setX(172);
        this->btnNext->onClick([&]() {
            this->game->quit();
        });
    } else {
        this->btnNext->onClick([&]() {
            this->game->setPaused(true);
            this->game->loadLevel(this->game->getCurrentLevel()->getNext());
            this->game->setPaused(false);
            this->game->setUI("Game");
        });
    }
}