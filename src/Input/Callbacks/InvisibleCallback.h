#ifndef GRIMWALL_INVISIBLECALLBACK_H
#define GRIMWALL_INVISIBLECALLBACK_H

#include "../KeypressCallback.h"

class InvisibleCallback : public KeypressCallback {
public:
    InvisibleCallback(IGame* game);
    virtual void execute() override;
};


#endif //GRIMWALL_INVISIBLECALLBACK_H
