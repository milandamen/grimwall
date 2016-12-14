//
// Created by stephanromer on 12/14/16.
//

#include "ScreenSelectHero.h"

ScreenSelectHero::ScreenSelectHero(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    manager->addImage("assets/gui/chooseYourHero.png", 140, 80, 680, 100);

    manager->addImage("assets/gui/heroDralas.png", 50, 180, 304, 575);
    GUIWidgetButton* bd = manager->addButton("", 60, 182);
        bd->setWidth(284);
        bd->setHeight(556);
        bd->setForegroundColor(255, 255, 255, 255);
        bd->setBackgroundColor(0, 0, 0, 0);
        bd->onClick([&]() {
            this->game->setHero(new Dralas());
            this->game->setUI("SelectLevel");
        });

    manager->addImage("assets/gui/heroHorwen.png", 375, 180, 304, 575);
    GUIWidgetButton* bh = manager->addButton("", 385, 182);
        bh->setWidth(285);
        bh->setHeight(556);
        bh->setForegroundColor(255, 255, 255, 255);
        bh->setBackgroundColor(0, 0, 0, 0);
        bh->onClick([&]() {
            std::cout << "Horwen does not exist, Dralas instead.";
            this->game->setHero(new Dralas());
            this->game->setUI("SelectLevel");
        });

    manager->addImage("assets/gui/heroZarrku.png", 700, 180, 304, 575);
    GUIWidgetButton* bz = manager->addButton("", 710, 182);
        bz->setWidth(284);
        bz->setHeight(556);
        bz->setForegroundColor(255, 255, 255, 255);
        bz->setBackgroundColor(0, 0, 0, 0);
        bz->onClick([&]() {
            this->game->setHero(new Zarrku());
            this->game->setUI("SelectLevel");
        });
}

ScreenSelectHero::~ScreenSelectHero()
{}