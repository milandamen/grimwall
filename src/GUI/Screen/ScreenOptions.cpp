
#include "ScreenOptions.h"

ScreenOptions::ScreenOptions(IGame* game, AGUIManager* manager)
        : GUI(manager), game(game)
{
    this->imgBg = manager->addImage("assets/gui/menubackground.png", 0, 0, 1024, 786);

    this->imgMusic = manager->addImage("assets/gui/settingMusic.png", 220, 340, 300, 80);
    this->stnMusic = manager->addImageButton("", "assets/gui/settingOn.png", 560, 340, 160, 80);
    this->stnMusic->onClick([&]() {
        int volume = EngineFacade::engine()->getVolume();

        if(volume == 0) {
            this->stnMusic->setAsset("assets/gui/settingOff.png");
            EngineFacade::engine()->setVolume(100);
        } else {
            this->stnMusic->setAsset("assets/gui/settingOn.png");
            EngineFacade::engine()->setVolume(0);
        }
    });

    /*this->imgSFX = manager->addImage("assets/gui/settingSFX.png", 220, 440, 300, 80);
    this->stnSFX = manager->addImageButton("", "assets/gui/settingOn.png", 560, 440, 160, 80);
    this->stnSFX->onClick([&]() {
        //if(sfxOn)
            this->stnSFX->setAsset("assets/gui/settingOff.png");
        //else
            this->stnSFX->setAsset("assets/gui/settingOn.png");
    });*/

    this->btnReturn = manager->addImageButton("", "assets/gui/settingReturn.png", 300, 600, 300, 80);
    this->btnReturn->onClick([&]() {
        this->game->setUI("MainMenu");
    });
}

ScreenOptions::~ScreenOptions()
{
    delete imgBg;
    delete imgMusic;
    delete stnMusic;
    delete imgSFX;
    delete stnMusic;
    delete btnReturn;
}