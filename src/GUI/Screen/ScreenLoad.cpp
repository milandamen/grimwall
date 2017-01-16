#include "ScreenLoad.h"

ScreenLoad::ScreenLoad(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    this->gameSlot1 = manager->addImageButton("", "assets/gui/btnSlot1.png", 62, 400, 300, 100);
    this->gameSlot1->onClick([&](){
        this->game->loadGame("slot1.sav");
        this->game->setUI("SelectHero");
    });

    this->gameSlot2 = manager->addImageButton("", "assets/gui/btnSlot2.png", 362, 400, 300, 100);
    this->gameSlot2->onClick([&](){
        this->game->loadGame("slot2.sav");
        this->game->setUI("SelectHero");
    });

    this->gameSlot3 = manager->addImageButton("", "assets/gui/btnSlot3.png", 662, 400, 300, 100);
    this->gameSlot3->onClick([&](){
        this->game->loadGame("slot3.sav");
        this->game->setUI("SelectHero");
    });


    this->loadSave = manager->addLabel("Load/Save", 50, 100);

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 230, 600, 570, 80);
    this->btnReturn->onClick([&]() {
        this->game->setUI("MainMenu");
    });
}

ScreenLoad::~ScreenLoad(){
    delete imgBg;
    delete loadSave;
    delete btnReturn;
    delete gameSlot1;
    delete gameSlot2;
    delete gameSlot3;
}