
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
    this->pgb_hero_hp = manager->createContainer(200, 20);
    this->pgb_hero_hp->setBackgroundColor(0, 255, 0, 255);
    this->lbl_hero_hp = manager->createLabel("");
    //this->lbl_hero_hp->setForegroundColor(0, 0, 0, 255);
    this->pgb_hero_mp = manager->createContainer(200, 20);
    this->pgb_hero_mp->setBackgroundColor(0, 0, 255, 255);
    this->lbl_hero_mp = manager->createLabel("");
    //this->lbl_hero_mp->setForegroundColor(0, 0, 0, 255);

    this->container->addWidget(this->lbl_hero_name, 10, 10);
    this->container->addWidget(this->pgb_hero_hp, 10, 30);
    this->container->addWidget(this->lbl_hero_hp, 10, 30);
    this->container->addWidget(this->pgb_hero_mp, 10, 50);
    this->container->addWidget(this->lbl_hero_mp, 10, 50);
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
    int hp = this->game->getHero()->getHitPoints();
    this->pgb_hero_hp->setWidth(hp);
    this->lbl_hero_hp->setCaption("HP: "+std::to_string(hp));
    this->pgb_hero_mp->setWidth(hp);
    this->lbl_hero_mp->setCaption("Mana: "+std::to_string(hp));
}

void ScreenGame::quitGame()
{
    this->game->setPaused(true);
    this->game->setUI("MainMenu");
}