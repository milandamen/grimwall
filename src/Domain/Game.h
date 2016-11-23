
#ifndef GRIMWALL_GAME_H
#define GRIMWALL_GAME_H


#include <vector>
#include "Units/Towers/ATower.h"
#include "Units/Towers/DefaultTower.h"

class Game {
private:
    /**
     * Set this to true to stop the game loop
     */
    bool quit {false};
    std::vector<ATower*> towers;
    void loadTowers();
    void deleteTowers();
public:
    Game();

};


#endif