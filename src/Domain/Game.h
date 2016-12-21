
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "EngineFacade.h"
#include "../Input/KeyboardMapper.h"
#include "Units/UnitManager.hpp"
#include "Units/Heroes/Dralas.h"
#include "Units/Buff/BoneStormBuff.h"
#include "UnitFactory.h"

#include <vector>

#include "../GUI/GUIRepo.h"
#include "../GUI/Screen/ScreenMainMenu.h"
#include "../GUI/Screen/ScreenSelectHero.h"
#include "../GUI/Screen/ScreenSelectLevel.h"
#include "../GUI/Screen/ScreenGameOver.h"
#include "../GUI/Screen/ScreenWon.h"
#include "../GUI/Screen/ScreenOptions.h"
#include "../GUI/Screen/ScreenPause.h"
#include "../GUI/Screen/ScreenGame.h"


class Game : public IGame {
private:

    /**
     * Manages the GUI's and prevents duplicates
     */
    GUIRepo* guirepo {nullptr};

    UnitManager<AHero>* hero {nullptr};

    /**
     * Set this to true to stop the game loop
     */
    std::vector<UnitManager<ATower>*> towers;
    void loadTowers();
    void deleteTowers();

    bool running {true};
    bool paused {false};

    /**
     * Value that denotes the current time
     */
    int curTime {};
    /**
     * Value that denotes the last time the FPS was updated
     */
    int lastTime {};

    /**
     * Value that denotes the score of the game
     */
    int score = 0;
    
    /**
     * Handles mapping of key combinations to callbacks
     */
    KeyboardMapper* keyboardMapper {nullptr};

    void initInput();
    void updateFPS();

    void tick();
public:
    Game();
    ~Game();

    virtual void setMap(std::string path) override;
    virtual bool isPaused() override;
    virtual void setPaused(bool paused) override;
    virtual void setHero(AHero* hero) override;
    virtual void setUI(std::string name) override;
    virtual int getCurrentScore() override;
    virtual UnitManager<AHero>* getHero() override;
    virtual void quit() override;
    virtual std::vector<UnitManager<ATower>*>* getTowers() override;
    virtual void letTowersAttack() override;
};


#endif