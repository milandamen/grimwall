
#include "ScreenGame.h"

ScreenGame::ScreenGame(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->manager = manager;
    this->container = manager->addContainer(0, 0, 1024, 200);
    this->container->setBackgroundColor(0, 0, 0, 128);

    this->manager->setX(0);
    this->manager->setY(600);
    this->manager->setWidth(1024);
    this->manager->setHeight(200);

    this->lbl_hero_name = manager->createLabel("Dit is tekst A");
    this->lbl_hero_hitpoints = manager->createLabel("");
    this->lbl_hero_mana = manager->createLabel("");

    this->container->addWidget(this->lbl_hero_name, 10, 10);
    this->container->addWidget(this->lbl_hero_hitpoints, 10, 30);
    this->container->addWidget(this->lbl_hero_mana, 10, 50);
}

ScreenGame::~ScreenGame()
{
    delete this->container;
}

void ScreenGame::hasBecomeActive()
{
    this->lbl_hero_name->setCaption(this->game->getHero()->getName());

    // Notifies us when a change on hero has happened
    this->game->getHero()->setStatsListener([&]() {
        this->updateStats();
    });

    this->updateStats();
}

void ScreenGame::hasBecomeInactive()
{
    this->game->getHero()->setStatsListener([](){}); // Reset update notifications
}

void ScreenGame::updateStats()
{
    this->lbl_hero_hitpoints->setCaption("HP: "+std::to_string(this->game->getHero()->getHitPoints()));
    this->lbl_hero_mana->setCaption("Mana: "+std::to_string(this->game->getHero()->getHitPoints()));
}

void ScreenGame::quitGame()
{
    this->game->setPaused(true);
    this->game->setUI("MainMenu");
}