//
// Created by stephanromer on 11/23/16.
//

#include "ScreenMainMenu.h"

ScreenMainMenu::ScreenMainMenu(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    manager->addImage("assets/gui/campaignMenuItem.png", 140, 350, 680, 100);
    GUIWidgetButton* bc = manager->addButton("", 140, 350);
    bc->setWidth(680);
    bc->setHeight(100);
    bc->setForegroundColor(255, 255, 255, 255);
    bc->setBackgroundColor(0, 0, 0, 0);
    bc->onClick([&](){
        this->game->setUI("SelectHero");
    });

    manager->addImage("assets/gui/optionsMenuItem.png", 140, 450, 680, 100);
    GUIWidgetButton* bo = manager->addButton("", 140, 450);
    bo->setWidth(680);
    bo->setHeight(100);
    bo->setForegroundColor(255, 255, 255, 255);
    bo->setBackgroundColor(0, 0, 0, 0);
    bo->onClick([&](){
        this->game->setUI("Options");
    });

    manager->addImage("assets/gui/exitMenuItem.png", 140, 550, 680, 100);
    GUIWidgetButton* be = manager->addButton("", 140, 550);
    be->setWidth(680);
    be->setHeight(100);
    be->setForegroundColor(255, 255, 255, 255);
    be->setBackgroundColor(0, 0, 0, 0);
    be->onClick([&](){
        game->quit();
    });
}

ScreenMainMenu::~ScreenMainMenu()
{}