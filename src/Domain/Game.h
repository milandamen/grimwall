
#ifndef GAME_H
#define GAME_H

#include "IGame.h"
#include "../Input/KeyboardMapper.h"

class Game : public IGame {
private:
    UnitManager* hero{nullptr};

    /**
     * Set this to true to stop the game loop
     */
    bool running {true};
    
    /**
     * Handles mapping of key combinations to callbacks
     */
    KeyboardMapper* keyboardMapper {nullptr};
    
    void initInput();
public:
    Game();
    ~Game();
    virtual UnitManager* getHero() override;
    virtual void quit() override;
};


#endif