#ifndef MOVE_TROUP_CALLBACK_H
#define MOVE_TROUP_CALLBACK_H

#include "../MouseCallback.h"
#include "../../Domain/IGame.h"

class MoveTroupCallback : public MouseCallback
{
public:
    MoveTroupCallback(IGame* game);
    virtual void execute() override;
};

#endif