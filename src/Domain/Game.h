
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "EngineFacade.h"
#include "../Input/KeyboardMapper.h"
#include "Units/UnitManager.hpp"
#include "Units/Heroes/Dralas.h"
#include "Units/Buff/BoneStormBuff.h"
#include "SaveGame/ISaveGameManager.h"
#include "SaveGame/SaveGameManager.h"
#include "UnitFactory.h"
#include "TowerManager.h"

#include <vector>

class Game : public IGame {
private:
    UnitManager<AHero>* hero{nullptr};

    std::vector<UnitManager<ATower>*> towers;
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
    
    ISaveGameManager* saveGameManager {nullptr};
    TowerManager towerManager;

    void initInput();
    void updateFPS();
    void loadTowers();
    void deleteTowers();
    void tick();
    void win();
    void lose();

public:
    Game();
    ~Game();
    virtual UnitManager<AHero>* getHero() override;
    virtual void quit() override;
    virtual std::vector<UnitManager<ATower>*>* getTowers() override;
    virtual ISaveGameManager* getSaveGameManager() override;
    virtual void setSaveGameManager(ISaveGameManager* saveGameManager) override;
};


#endif
