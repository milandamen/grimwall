
#include "ScreenSelectHero.h"
#include "../../Domain/Units/Heroes/Abilities/DeathStrike.h"
#include "../../Domain/Units/Heroes/Abilities/BoneStorm.h"
#include "../../Domain/Units/Heroes/Abilities/RageOfTheUndead.h"
#include "../../Domain/Units/Heroes/Abilities/WorldOfTheUndead.h"
#include "../../Domain/Units/Heroes/Abilities/Bomb.h"
#include "../../Domain/Units/Heroes/Abilities/Stealth.h"
#include "../../Domain/Units/Heroes/Abilities/EvasiveManeuvers.h"
#include "../../Domain/Units/Heroes/Abilities/SmokeBomb.h"

ScreenSelectHero::ScreenSelectHero(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    manager->addImage("assets/gui/chooseYourHero.png", 140, 80, 680, 100);

    manager->addImage("assets/gui/heroDralas.png", 50, 180, 304, 575);
    GUIWidgetButton* bd = manager->addButton("", 60, 182);
        bd->setWidth(284);
        bd->setHeight(556);
        bd->setForegroundColor(255, 255, 255, 255);
        bd->setBackgroundColor(0, 0, 0, 0);
        bd->onClick([&]() {
            this->game->setHero(new Dralas());
            this->game->getHero()->getBase()->addAbility(new DeathStrike(this->game->getHero()));
            this->game->getHero()->getBase()->addAbility(new BoneStorm(this->game->getTowers()));
            this->game->getHero()->getBase()->addAbility(new RageOfTheUndead(this->game->getTroupManager()->getTroups()));
            this->game->getHero()->getBase()->addAbility(new WorldOfTheUndead(this->game->getHero()));
            this->game->setUI("SelectLevel");
        });

    manager->addImage("assets/gui/heroHorwen.png", 375, 180, 304, 575);
    GUIWidgetButton* bh = manager->addButton("", 385, 182);
        bh->setWidth(285);
        bh->setHeight(556);
        bh->setForegroundColor(255, 255, 255, 255);
        bh->setBackgroundColor(0, 0, 0, 0);
        bh->onClick([&]() {
            std::cout << "Horwen does not exist, Dralas instead.";
            this->game->setHero(new Dralas());
            this->game->setUI("SelectLevel");
        });

    manager->addImage("assets/gui/heroZarrku.png", 700, 180, 304, 575);
    GUIWidgetButton* bz = manager->addButton("", 710, 182);
        bz->setWidth(284);
        bz->setHeight(556);
        bz->setForegroundColor(255, 255, 255, 255);
        bz->setBackgroundColor(0, 0, 0, 0);
        bz->onClick([&]() {
            this->game->setHero(new Zarrku());
            this->game->getHero()->getBase()->addAbility(new Bomb(this->game->getHero(), this->game->getTowers()));
            this->game->getHero()->getBase()->addAbility(new Stealth(this->game->getHero()));
            this->game->getHero()->getBase()->addAbility(new EvasiveManeuvers(this->game->getHero()));
            this->game->getHero()->getBase()->addAbility(new SmokeBomb(this->game->getHero()));
            this->game->setUI("SelectLevel");
        });
}

ScreenSelectHero::~ScreenSelectHero()
{}