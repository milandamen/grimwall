
#include "ScreenWon.h"

ScreenWon::ScreenWon(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    manager->addLabel("You have won!", 140, 350);
    manager->addLabel("Score: " + this->game->getCurrentScore(), 140, 360);

    manager->addImage("assets/gui/exitMenuItem.png", 140, 550, 680, 100);
    GUIWidgetButton* b = manager->addButton("Quit", 140, 550);
    b->setWidth(680);
    b->setHeight(100);
    b->setForegroundColor(255, 255, 255, 255);
    b->setBackgroundColor(0, 0, 0, 0);
    b->onClick([&]() {
        game->quit();
    });
}

ScreenWon::~ScreenWon()
{}