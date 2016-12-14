//
// Created by stephanromer on 12/14/16.
//

#include "ScreenGame.h"


ScreenGame::ScreenGame(IGame* game, AGUIManager* manager)
        : game(game), GUI(manager)
{
    this->rightMenuContainer = manager->addContainer(924, 40, 100, 120);

    this->rightMenuBtnSettings = manager->createButton("Settings");
    this->rightMenuBtnSettings->setWidth(100);
    this->rightMenuBtnSettings->setHeight(40);
    this->rightMenuBtnSettings->onClick([&]() {
        this->showOptions();
    });
    this->rightMenuContainer->addWidget(this->rightMenuBtnSettings);

    this->rightMenuBtnQuit = manager->createButton("Quit game");
    this->rightMenuBtnQuit->setWidth(100);
    this->rightMenuBtnQuit->setHeight(40);
    this->rightMenuBtnQuit->onClick([&]() {
        this->quitGame();
    });
    this->rightMenuContainer->addWidget(this->rightMenuBtnQuit);
    this->rightMenuBtnQuit->setY(40);

    this->rightMenuBtnPause = manager->createButton("Pause game");
    this->rightMenuBtnPause->setWidth(100);
    this->rightMenuBtnPause->setHeight(40);
    this->rightMenuBtnPause->onClick([&]() {
        this->togglePauseGame();
    });
    this->rightMenuContainer->addWidget(this->rightMenuBtnPause);
    this->rightMenuBtnPause->setY(80);

    this->rightMenuContainer->setBackgroundColor(0,0,0,100); // Black 50%
    this->rightMenuContainer->setVisible(false);

    this->rightMenu = manager->addButton("Options", 924, 0);
    this->rightMenu->setIdentifier("options");
    this->rightMenu->setWidth(100);
    this->rightMenu->setHeight(40);
    this->rightMenu->onClick([&]() {
        this->toggleRightMenu();
    });

    this->rightMenu->onClick([&](AGUIWidget* widget) {
        std::cout << widget->getIdentifier();
    });
}

ScreenGame::~ScreenGame()
{
    delete this->rightMenu;
    delete this->rightMenuBtnQuit;
    delete this->rightMenuBtnPause;
    delete this->rightMenuBtnSettings;
    delete this->rightMenuContainer;
}

void ScreenGame::toggleRightMenu()
{
    this->rightMenuContainer->setVisible(!this->rightMenuContainer->isVisible());
}

void ScreenGame::togglePauseGame()
{
    bool paused = this->game->isPaused();
    if(paused)
        this->rightMenuBtnPause->setCaption("Pause game");
    else
        this->rightMenuBtnPause->setCaption("Resume game");

    this->game->setPaused(!paused);
}

void ScreenGame::showOptions()
{
    this->game->setPaused(true);
    this->game->setUI("Options");
}

void ScreenGame::quitGame()
{
    this->game->setPaused(true);
    this->game->setUI("MainMenu");
}