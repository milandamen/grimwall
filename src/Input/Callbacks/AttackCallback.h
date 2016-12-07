

#ifndef GRIMWALL_ATTACKCALLBACK_H
#define GRIMWALL_ATTACKCALLBACK_H


#include "../KeypressCallback.h"

class AttackCallback : public KeypressCallback {
public:
    AttackCallback(IGame* game);
    virtual void execute() override;
};


#endif //GRIMWALL_ATTACKCALLBACK_H
