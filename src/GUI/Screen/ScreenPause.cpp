//
// Created by stephanromer on 12/21/16.
//

#include "ScreenPause.h"

ScreenPause::ScreenPause(IGame *game, AGUIManager *manager)
        : GUI(manager), game(game)
{
    this->fog = manager->addContainer(0, 0, 1024, 768);
    this->fog->setBackgroundColor(0, 0, 0, 128);

    this->btnAd = manager->addImageButton("", "assets/ads/advert.png", 212, 50, 600, 70);
    this->btnAd->setBackgroundColor(0, 0, 0, 0);
    this->btnAd->onClick([](){
        system("firefox https://www.linux.com/");
    });

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 363, 600, 300, 80);
    this->btnReturn->onClick([&]() {
        this->game->setUI("Game");
        this->game->setPaused(false);
    });
}

ScreenPause::~ScreenPause()
{
    delete this->fog;
    delete this->btnAd;
    delete this->btnReturn;
}