
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
    this->pgbHeroHP = manager->createContainer(200, 40);
    this->pgbHeroHP->setBackgroundColor(0, 255, 0, 255);
    this->lblHeroHP = manager->createLabel("");
    this->lblHeroHP->setForegroundColor(0, 0, 0, 255);
    this->pgbHeroMP = manager->createContainer(200, 40);
    this->pgbHeroMP->setBackgroundColor(0, 0, 255, 255);
    this->lblHeroMP = manager->createLabel("");
    this->lblHeroMP->setForegroundColor(0, 0, 0, 255);

    this->lblAbilitie1Name = manager->createLabel("Abilitie Q");
    this->lblAbilitie1Key = manager->createLabel("Q");
    this->lblAbilitie2Name = manager->createLabel("Abilitie W");
    this->lblAbilitie2Key = manager->createLabel("W");
    this->lblAbilitie3Name = manager->createLabel("Abilitie E");
    this->lblAbilitie3Key = manager->createLabel("E");
    this->lblAbilitie4Name = manager->createLabel("Abilitie R");
    this->lblAbilitie4Key = manager->createLabel("R");

    this->btnPause = manager->addButton("Pause", 1024-80, 100);
    this->btnPause->setWidth(60);
    this->btnPause->setHeight(40);
    this->btnPause->onClick([&](){ this->pause(); });

    this->container->addWidget(this->lblAbilitie1Name, 250, 10);
    this->container->addWidget(this->lblAbilitie1Key, 250, 30);
    this->container->addWidget(this->lblAbilitie2Name, 420, 10);
    this->container->addWidget(this->lblAbilitie2Key, 420, 30);
    this->container->addWidget(this->lblAbilitie3Name, 580, 10);
    this->container->addWidget(this->lblAbilitie3Key, 580, 30);
    this->container->addWidget(this->lblAbilitie4Name, 800, 10);
    this->container->addWidget(this->lblAbilitie4Key, 800, 30);

    this->container->addWidget(this->lblHeroName, 10, 10);
    this->container->addWidget(this->pgbHeroHP, 10, 60);
    this->container->addWidget(this->lblHeroHP, 20, 70);
    this->container->addWidget(this->pgbHeroMP, 10, 110);
    this->container->addWidget(this->lblHeroMP, 20, 120);
}

ScreenGame::~ScreenGame()
{
    delete this->lblHeroName;
    delete this->pgbHeroHP;
    delete this->lblHeroHP;
    delete this->pgbHeroMP;
    delete this->lblHeroMP;
    delete this->container;
    delete this->lblAbilitie1Name;
    delete this->lblAbilitie1Key;
    delete this->lblAbilitie2Name;
    delete this->lblAbilitie2Key;
    delete this->lblAbilitie3Name;
    delete this->lblAbilitie3Key;
    delete this->lblAbilitie4Name;
    delete this->lblAbilitie4Key;

    this->deleteBuffs();
}

void ScreenGame::deleteBuffs() {
    for (auto& ability : this->lblBuffs) {
        delete ability;
    }

    this->lblBuffs.clear();
}

void ScreenGame::hasBecomeActive()
{
    AAbility* ability1 = this->game->getHero()->getBase()->getAbility(0);
    this->lblAbilitie1Name->setCaption(ability1->getName() + " (" + std::to_string(ability1->getCost()) + ")");

    AAbility* ability2 = this->game->getHero()->getBase()->getAbility(1);
    this->lblAbilitie2Name->setCaption(ability2->getName() + " (" + std::to_string(ability2->getCost()) + ")");

    AAbility* ability3 = this->game->getHero()->getBase()->getAbility(2);
    this->lblAbilitie3Name->setCaption(ability3->getName() + " (" + std::to_string(ability3->getCost()) + ")");

    AAbility* ability4 = this->game->getHero()->getBase()->getAbility(3);
    this->lblAbilitie4Name->setCaption(ability4->getName() + " (" + std::to_string(ability4->getCost()) + ")");

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

    this->deleteBuffs();
    int i = 0;
    for (auto& ability : this->game->getHero()->getBuffs()) {
        GUIWidgetLabel* lblBuff = manager->createLabel(ability);
        this->container->addWidget(lblBuff, 250, 100 + (10*i));
        this->lblBuffs.push_back(lblBuff);
        i++;
    }

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