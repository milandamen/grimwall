
#ifndef GAME_H
#define GAME_H

#include <vector>

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
#include "../GUI/GUIRepo.h"
#include "Levels/Level1.h"
#include "Levels/Level2.h"
#include "Levels/Level3.h"
#include "Units/Heroes/Abilities/DeathStrike.h"

#include <vector>


class Game : public IGame {
private:

    TroupManager troupManager;

    /**
     * Manages the GUI's and prevents duplicates
     */
    GUIRepo* guirepo {nullptr};
    GUI* activeGUI {nullptr};

    UnitManager<AHero>* hero {nullptr};

    std::vector<UnitManager<ATower>*> towers;

    /**
     * Set this to true to stop the game loop
     */
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
    
    ISaveGameManager* saveGameManager {nullptr};
    TowerManager towerManager;

    ILevel* currentLevel {nullptr};
    std::map<std::string, ILevel*> levels;

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
    virtual void init () override;
    virtual TroupManager* getTroupManager() override;
    virtual void loadLevel(std::string levelName) override;
    virtual ILevel* getCurrentLevel() override;
    virtual void setMap(std::string path) override;
    virtual bool isPaused() override;
    virtual void setPaused(bool paused) override;
    virtual void setHero(AHero* hero) override;
    virtual void setUI(std::string name) override;
    virtual int getCurrentScore() override;
    virtual UnitManager<AHero>* getHero() override;
    virtual void quit() override;
    virtual std::vector<UnitManager<ATower>*>* getTowers() override;
    virtual ISaveGameManager* getSaveGameManager() override;
    virtual void setSaveGameManager(ISaveGameManager* saveGameManager) override;
};


#endif
