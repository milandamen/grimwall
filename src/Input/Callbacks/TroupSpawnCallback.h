

#ifndef GRIMWALL_TROUPSPAWNCALLBACK_H
#define GRIMWALL_TROUPSPAWNCALLBACK_H

#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"
#include "../../Domain/EngineFacade.h"

#include <iostream>

class TroupSpawnCallback : public KeypressCallback{
private:
    std::string value;
public:
    TroupSpawnCallback(IGame* game, std::string value);
    virtual void execute() override;
};


#endif //GRIMWALL_TROUPSPAWNCALLBACK_H
