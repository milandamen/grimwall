
#include "ScreenHighscores.h"

ScreenHighscores::ScreenHighscores(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/backgroundMenu.png", 0, 0, 1024, 768);

    this->lblSlot1 = manager->addLabel("", 172, 300);
    this->lblSlot1->setWidth(200);
    this->lblSlot1->setHeight(100);
    this->lblSlot1->setAlignment(GUITextAlignment::Center);

    this->lblSlot2 = manager->addLabel("", 402, 300);
    this->lblSlot2->setWidth(200);
    this->lblSlot2->setHeight(100);
    this->lblSlot2->setAlignment(GUITextAlignment::Center);

    this->lblSlot3 = manager->addLabel("", 632, 300);
    this->lblSlot3->setWidth(200);
    this->lblSlot3->setHeight(100);
    this->lblSlot3->setAlignment(GUITextAlignment::Center);

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 172, 650, 680, 100);
    this->btnReturn->setForegroundColor(255, 255, 255, 255);
    this->btnReturn->setBackgroundColor(0, 0, 0, 0);
    this->btnReturn->onClick([&]() {
        this->game->setUI("MainMenu");
    });
}

ScreenHighscores::~ScreenHighscores()
{
    delete this->imgBg;
    delete this->btnReturn;
}

void ScreenHighscores::hasBecomeActive()
{
    if(!this->loaded) {
        this->loaded = true;

        SaveGame* s1 = this->game->getSaveGameManager()->load("slot1.sav");
        SaveGame* s2 = this->game->getSaveGameManager()->load("slot2.sav");
        SaveGame* s3 = this->game->getSaveGameManager()->load("slot3.sav");

        this->lblSlot1->setCaption("Score: " + s1->score);
        this->lblSlot2->setCaption("Score: " + s2->score);
        this->lblSlot3->setCaption("Score: " + s3->score);

        delete s1;
        delete s2;
        delete s3;
    }
}
