
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "../Input/KeyboardMapper.h"

class Game : public IGame {
private:
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
    virtual void quit() override;
};


#endif