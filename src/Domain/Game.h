
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
#include "Units/Troups/ATroup.h"

class Game : public IGame {
private:
    UnitManager<AHero>* hero{nullptr};

    std::vector<ATroup*> troups;
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
    virtual UnitManager<AHero>* getHero() override;
    virtual UnitManager<std::vector<ATroup*> >* getTroups() override;
    virtual void quit() override;
};


#endif