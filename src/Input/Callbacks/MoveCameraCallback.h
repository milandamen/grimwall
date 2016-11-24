#ifndef GRIMWALL_MOVECAMERACALLBACK_H
#define GRIMWALL_MOVECAMERACALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"
#include "../../Domain/EngineFacade.h"

#include <iostream>


class MoveCameraCallback : public KeypressCallback {
private:
    std::string direction;
public:
    MoveCameraCallback(IGame* game, std::string direction);
    virtual void execute() override;
};


#endif //GRIMWALL_MOVECAMERACALLBACK_H
