

#ifndef GRIMWALL_TROUPMOVECALLBACK_H
#define GRIMWALL_TROUPMOVECALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"
#include "../../Domain/EngineFacade.h"

#include <iostream>

class TroupMoveCallback : public KeypressCallback{
private:
    std::string value;
public:
    TroupMoveCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif //GRIMWALL_TROUPMOVECALLBACK_H
