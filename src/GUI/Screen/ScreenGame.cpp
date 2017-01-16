
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

    this->lblHeroName = manager->createLabel("Dit is tekst A");
    this->pgbHeroHP = manager->createContainer(200, 20);
    this->pgbHeroHP->setBackgroundColor(0, 255, 0, 255);
    this->lblHeroHP = manager->createLabel("");
    this->pgbHeroMP = manager->createContainer(200, 20);
    this->pgbHeroMP->setBackgroundColor(0, 0, 255, 255);
    this->lblHeroMP = manager->createLabel("");

    this->btnPause = manager->addButton("Pause", 1024-40, 20);
    this->btnPause->setWidth(40);
    this->btnPause->setHeight(40);
    this->btnPause->onClick([&](){ this->pause(); });

    this->container->addWidget(this->lblHeroName, 10, 10);
    this->container->addWidget(this->pgbHeroHP, 10, 30);
    this->container->addWidget(this->lblHeroHP, 10, 30);
    this->container->addWidget(this->pgbHeroMP, 10, 50);
    this->container->addWidget(this->lblHeroMP, 10, 50);
}

ScreenGame::~ScreenGame()
{
    delete this->lblHeroName;
    delete this->pgbHeroHP;
    delete this->lblHeroHP;
    delete this->pgbHeroMP;
    delete this->lblHeroMP;
    delete this->container;
}

void ScreenGame::hasBecomeActive()
{
    this->lblHeroName->setCaption(this->game->getHero()->getName());
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
    int mp = this->game->getHero()->getBase()->getMana();
    this->pgbHeroHP->setWidth(hp);
    this->lblHeroHP->setCaption("HP: "+std::to_string(hp));
    this->pgbHeroMP->setWidth(mp);
    this->lblHeroMP->setCaption("Mana: "+std::to_string(mp));
}

void ScreenGame::pause()
{
    this->game->setPaused(true);
    this->game->setUI("Pause");
}

void ScreenGame::quitGame()
{
    this->game->setPaused(true);
    this->game->setUI("MainMenu");
}