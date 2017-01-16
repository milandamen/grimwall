#include "ScreenLoad.h"

ScreenLoad::ScreenLoad(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    gameSlot1 = manager->addButton("SLOT 1", 230, 325);
    gameSlot1->setWidth(150);
    gameSlot1->setHeight(150);

    gameSlot2 = manager->addButton("SLOT 2", 440, 325);
    gameSlot2->setWidth(150);
    gameSlot2->setHeight(150);

    gameSlot3 = manager->addButton("SLOT 3", 650, 325);
    gameSlot3->setWidth(150);
    gameSlot3->setHeight(150);


    loadSave = manager->addLabel("Load/Save", 50, 100);

    btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 230, 600, 570, 80);
    btnReturn->onClick([&]() {
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