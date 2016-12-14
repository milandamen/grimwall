
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "EngineFacade.h"
#include "../Input/KeyboardMapper.h"
#include "Units/UnitManager.h"
#include "Units/Heroes/Dralas.h"
#include "Units/Buff/BoneStormBuff.h"

#include <vector>
#include "Units/Towers/ATower.h"
#include "Units/Towers/DefaultTower.h"

#include "../GUI/GUIRepo.h"
#include "../GUI/Screen/ScreenMainMenu.h"
#include "../GUI/Screen/ScreenSelectHero.h"
#include "../GUI/Screen/ScreenSelectLevel.h"
#include "../GUI/Screen/ScreenGameOver.h"
#include "../GUI/Screen/ScreenWon.h"
#include "../GUI/Screen/ScreenOptions.h"
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
    std::vector<ATower*> towers;
    void loadTowers();
    void deleteTowers();

    bool isRunning {true};
    bool isPaused {false};

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
public:
    Game();
    ~Game();

    virtual void setMap(std::string path) override;
    virtual void setPaused(bool paused) override;
    virtual void setHero(AHero* hero) override;
    virtual void setUI(std::string name) override;
    virtual int getCurrentScore() override;
    virtual UnitManager<AHero>* getHero() override;
    virtual void quit() override;
};


#endif