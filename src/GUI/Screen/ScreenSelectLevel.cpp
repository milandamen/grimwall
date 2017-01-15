
#include "ScreenSelectLevel.h"

ScreenSelectLevel::ScreenSelectLevel(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    GUIWidgetButton* bh = manager->addButton("Level 1", 385, 182);
    bh->setWidth(285);
    bh->setHeight(556);

    bh->onClick([&]() {
        this->game->setMap("assets/maps/level1_complete.xml");

        // TODO: Set hero on spawn location
        EngineFacade::engine()->createInstance(this->game->getHero()->getName(), this->game->getHero()->getName(), 0, 0);

        this->game->setPaused(false);
        this->game->setUI("Game");
    });
}

ScreenSelectLevel::~ScreenSelectLevel()
{}