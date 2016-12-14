
#ifndef GAME_H
#define GAME_H

#include <vector>

#include "IGame.h"
#include "EngineFacade.h"
#include "../Input/KeyboardMapper.h"
#include "Units/UnitManager.h"
#include "Units/Heroes/Dralas.h"
#include "Units/Buff/BoneStormBuff.h"
#include "Units/Towers/ATower.h"
#include "Units/Towers/DefaultTower.h"

class Game : public IGame {
private:
    UnitManager<AHero>* hero{nullptr};

    TroupManager* troupManager;

    std::vector<ATower*> towers;
    void loadTowers();
    void deleteTowers();
    /**
     * Set this to true to stop the game loop
     */
    bool running {true};

    /**
     * Value that denotes the current time
     */
    int curTime {};
    /**
     * Value that denotes the last time the FPS was updated
     */
    int lastTime {};
    
    /**
     * Handles mapping of key combinations to callbacks
     */
    KeyboardMapper* keyboardMapper {nullptr};

    void initInput();
    void updateFPS();
public:
    Game();
    ~Game();
    TroupManager* getTroupManager();
    virtual UnitManager<AHero>* getHero() override;
    virtual void quit() override;
};


#endif