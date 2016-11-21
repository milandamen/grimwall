
#ifndef GRIMWALL_GAME_H
#define GRIMWALL_GAME_H

#include "../Input/KeyboardMapper.h"

class Game {
private:
    /**
     * Set this to true to stop the game loop
     */
    bool running {true};
public:
    Game();
    void quit();
};


#endif