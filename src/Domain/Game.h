
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "../Input/KeyboardMapper.h"

#include <vector>
#include "Units/Towers/ATower.h"
#include "Units/Towers/DefaultTower.h"

class Game : public IGame {
private:
    AHero* hero{nullptr};

    /**
     * Set this to true to stop the game loop
     */
    bool quit {false};
    std::vector<ATower*> towers;
    void loadTowers();
    void deleteTowers();
    bool running {true};

    /**
     * Handles mapping of key combinations to callbacks
     */
    KeyboardMapper* keyboardMapper {nullptr};

    void initInput();
public:
    Game();
    ~Game();
    virtual AHero* getHero() override;
    virtual void quit() override;
};


#endif