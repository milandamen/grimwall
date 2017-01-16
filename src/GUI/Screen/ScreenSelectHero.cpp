
#include "ScreenSelectHero.h"
#include "../../Domain/Units/Heroes/Abilities/DeathStrike.h"

ScreenSelectHero::ScreenSelectHero(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/heroSelectBackground.png", 0, 0, 1024, 786);
    this->imgChooseYourHero = manager->addImage("assets/gui/chooseYourHero.png", 140, 80, 680, 100);

    this->btnDralas = manager->addImageButton("", "assets/gui/heroDralas.png", 304, 575, 50, 180);
    this->btnDralas->onClick([&]() {
        this->game->setHero(new Dralas());
        this->game->getHero()->getBase()->addAbility(new DeathStrike(this->game->getHero()));
        this->game->setUI("SelectLevel");
    });

    this->btnHorwen = manager->addImageButton("", "assets/gui/heroHorwen.png", 304, 575, 385, 180);
    this->btnHorwen->onClick([&]() {
        std::cout << "Horwen does not exist, Dralas instead.";
        this->game->setHero(new Dralas());
        this->game->setUI("SelectLevel");
    });
    
    this->btnZarrku = manager->addImageButton("", "assets/gui/heroZarrku.png", 304, 575, 700, 180);
    this->btnZarrku->onClick([&]() {
        this->game->setHero(new Zarrku());
        this->game->setUI("SelectLevel");
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