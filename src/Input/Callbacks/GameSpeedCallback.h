

#ifndef GRIMWALL_GAMESPEEDCALLBACK_H
#define GRIMWALL_GAMESPEEDCALLBACK_H

#include "../KeypressCallback.h"

class GameSpeedCallback : public KeypressCallback {
private:
    int limit;
public:
    GameSpeedCallback(int limit);
    virtual void execute() override;
};


#endif //GRIMWALL_GAMESPEEDCALLBACK_H
