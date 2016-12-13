//
// Created by stephanromer on 11/23/16.
//

#include "MainMenu.h"

MainMenu::MainMenu(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    manager->addImage("assets/gui/campaignMenuItem.png", 140, 350, 680, 100);
    manager->addImage("assets/gui/optionsMenuItem.png", 140, 450, 680, 100);
    manager->addImage("assets/gui/exitMenuItem.png", 140, 550, 680, 100);

    GUIWidgetButton* b = manager->addButton("", 140, 550);
    b->setWidth(680);
    b->setHeight(100);
    b->setForegroundColor(255, 255, 255, 255);
    b->setBackgroundColor(0, 0, 0, 0);
    b->onClick([&](){
        game->quit();
    });
}

MainMenu::~MainMenu()
{}