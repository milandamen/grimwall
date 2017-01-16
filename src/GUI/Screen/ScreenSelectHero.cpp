
#include "ScreenSelectHero.h"
#include "../../Domain/Units/Heroes/Abilities/DeathStrike.h"
#include "../../Domain/Units/Heroes/Abilities/BoneStorm.h"
#include "../../Domain/Units/Heroes/Abilities/RageOfTheUndead.h"
#include "../../Domain/Units/Heroes/Abilities/WorldOfTheUndead.h"
#include "../../Domain/Units/Heroes/Abilities/Bomb.h"
#include "../../Domain/Units/Heroes/Abilities/Stealth.h"
#include "../../Domain/Units/Heroes/Abilities/EvasiveManeuvers.h"
#include "../../Domain/Units/Heroes/Abilities/SmokeBomb.h"
#include "../../Domain/Units/Heroes/Abilities/StrikeOfReflection.h"
#include "../../Domain/Units/Heroes/Abilities/Rage.h"
#include "../../Domain/Units/Heroes/Abilities/Execution.h"
#include "../../Domain/Units/Heroes/Abilities/ShieldOfJustice.h"

ScreenSelectHero::ScreenSelectHero(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    this->imgChooseYourHero = manager->addImage("assets/gui/chooseYourHero.png", 140, 80, 680, 100);
    
    this->btnDralas = manager->addImageButton("", "assets/gui/heroDralas.png", 50, 180, 304, 575);
    this->btnDralas->onClick([&]() {
        this->game->setHero(new Dralas());
        this->game->getHero()->getBase()->addAbility(new DeathStrike(this->game->getHero()));
        this->game->getHero()->getBase()->addAbility(new BoneStorm(this->game->getTowers()));
        this->game->getHero()->getBase()->addAbility(new RageOfTheUndead(this->game->getTroupManager()->getTroups()));
        this->game->getHero()->getBase()->addAbility(new WorldOfTheUndead(this->game->getHero()));
        this->game->loadLevel(this->game->getCurrentLevel()->getName());
        this->game->setUI("Game");
        this->game->setPaused(false);
    });

    this->btnHorwen = manager->addImageButton("", "assets/gui/heroHorwen.png", 375, 180, 304, 575);
    this->btnHorwen->onClick([&]() {
        this->game->setHero(new Horwen());
        this->game->getHero()->getBase()->addAbility(new StrikeOfReflection(this->game->getHero()));
        this->game->getHero()->getBase()->addAbility(new Rage(this->game->getHero()));
        this->game->getHero()->getBase()->addAbility(new Execution(this->game->getHero(), this->game->getTowers()));
        this->game->getHero()->getBase()->addAbility(new ShieldOfJustice(this->game->getHero()));
        this->game->loadLevel(this->game->getCurrentLevel()->getName());
        this->game->setUI("Game");
        this->game->setPaused(false);
    });

    this->btnZarrku = manager->addImageButton("", "assets/gui/heroZarrku.png", 700, 180, 304, 575);
    this->btnZarrku->onClick([&]() {
        this->game->setHero(new Zarrku());
        this->game->getHero()->getBase()->addAbility(new Bomb(this->game->getHero(), this->game->getTowers()));
        this->game->getHero()->getBase()->addAbility(new Stealth(this->game->getHero()));
        this->game->getHero()->getBase()->addAbility(new EvasiveManeuvers(this->game->getHero()));
        this->game->getHero()->getBase()->addAbility(new SmokeBomb(this->game->getHero()));
        this->game->loadLevel(this->game->getCurrentLevel()->getName());
        this->game->setUI("Game");
        this->game->setPaused(true);
    });
}

ScreenSelectHero::~ScreenSelectHero()
{
    delete this->imgBg;
    delete this->imgChooseYourHero;
    delete this->btnDralas;
    delete this->btnHorwen;
    delete this->btnZarrku;
}