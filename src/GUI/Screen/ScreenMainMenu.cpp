
#include "ScreenMainMenu.h"

ScreenMainMenu::ScreenMainMenu(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/backgroundMenu.png", 0, 0, 1024, 786);

    this->btnCampaign = manager->addImageButton("", "assets/gui/campaignMenuItem.png", 172, 200, 680, 100);
    this->btnCampaign->setForegroundColor(255, 255, 255, 255);
    this->btnCampaign->setBackgroundColor(0, 0, 0, 0);
    this->btnCampaign->onClick([&](){
        this->game->setUI("Load");
    });

    this->btnOptions = manager->addImageButton("", "assets/gui/optionsMenuItem.png", 172, 300, 680, 100);
    this->btnOptions->setForegroundColor(255, 255, 255, 255);
    this->btnOptions->setBackgroundColor(0, 0, 0, 0);
    this->btnOptions->onClick([&]() {
        this->game->setUI("Options");
    });

    this->btnHighscores = manager->addImageButton("", "assets/gui/btnHighscores.png", 172, 400, 680, 100);
    this->btnHighscores->setForegroundColor(255, 255, 255, 255);
    this->btnHighscores->setBackgroundColor(0, 0, 0, 0);
    this->btnHighscores->onClick([&]() {
        this->game->setUI("Highscores");
    });

    this->btnOptions = manager->addImageButton("", "assets/gui/btnCredits.png", 172, 500, 680, 100);
    this->btnOptions->setForegroundColor(255, 255, 255, 255);
    this->btnOptions->setBackgroundColor(0, 0, 0, 0);
    this->btnOptions->onClick([&]() {
        this->game->setUI("Credits");
    });

    this->btnExit = manager->addImageButton("", "assets/gui/exitMenuItem.png", 172, 600, 680, 100);
    this->btnExit->setForegroundColor(255, 255, 255, 255);
    this->btnExit->setBackgroundColor(0, 0, 0, 0);
    this->btnExit->onClick([&]() {
        this->game->quit();
    });

}

ScreenMainMenu::~ScreenMainMenu()
{
    delete imgBg;
    delete btnCampaign;
    delete btnHighscores;
    delete btnOptions;
    delete btnExit;
}