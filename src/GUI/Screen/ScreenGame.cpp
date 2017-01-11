
#include "ScreenGame.h"

ScreenGame::ScreenGame(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->container = manager->addContainer(0, 0, 1024, 200);
    this->container->setBackgroundColor(0, 0, 0, 128);

    this->manager->setX(0);
    this->manager->setY(600);
    this->manager->setWidth(1024);
    this->manager->setHeight(200);
}

ScreenGame::~ScreenGame()
{
    delete this->container;
}

void ScreenGame::quitGame()
{
    this->game->setPaused(true);
    this->game->setUI("MainMenu");
}