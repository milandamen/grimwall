
#include "ScreenGameOver.h"

ScreenGameOver::ScreenGameOver(IGame* game,AGUIManager* manager)
        : GUI(manager), game(game)
{
    manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);
    manager->addLabel("Game Over!", 140, 350);

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

ScreenGameOver::~ScreenGameOver()
{}