
#include "ScreenMainMenu.h"

ScreenMainMenu::ScreenMainMenu(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    this->btnLoad = manager->addButton("Load and Save", 0, 0);
    this->btnLoad->setWidth(150);
    this->btnLoad->setHeight(150);
    this->btnLoad->onClick([&](){
        this->game->setUI("Load");
    });

    this->btnCampaign = manager->addImageButton("", "assets/gui/campaignMenuItem.png", 172, 350, 680, 100);
    this->btnCampaign->setForegroundColor(255, 255, 255, 255);
    this->btnCampaign->setBackgroundColor(0, 0, 0, 0);
    this->btnCampaign->onClick([&](){
        this->game->setUI("SelectHero");
    });

    this->btnOptions = manager->addImageButton("", "assets/gui/optionsMenuItem.png", 172, 450, 680, 100);
    this->btnOptions->setForegroundColor(255, 255, 255, 255);
    this->btnOptions->setBackgroundColor(0, 0, 0, 0);
    this->btnOptions->onClick([&](){
        this->game->setUI("Options");
    });

    this->btnOptions = manager->addImageButton("", "assets/gui/btnCredits.png", 172, 550, 680, 100);
    this->btnOptions->setForegroundColor(255, 255, 255, 255);
    this->btnOptions->setBackgroundColor(0, 0, 0, 0);
    this->btnOptions->onClick([&](){
        this->game->setUI("Credits");
    });

    this->btnExit = manager->addImageButton("", "assets/gui/exitMenuItem.png", 172, 650, 680, 100);
    this->btnExit->setForegroundColor(255, 255, 255, 255);
    this->btnExit->setBackgroundColor(0, 0, 0, 0);
    this->btnExit->onClick([&](){
        this->game->quit();
    });

}

ScreenMainMenu::~ScreenMainMenu()
{
    delete imgBg;
    delete btnCampaign;
    delete btnOptions;
    delete btnExit;
}