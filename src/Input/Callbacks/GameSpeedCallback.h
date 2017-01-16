

#ifndef GRIMWALL_GAMESPEEDCALLBACK_H
#define GRIMWALL_GAMESPEEDCALLBACK_H

#include "../KeypressCallback.h"

class GameSpeedCallback : public KeypressCallback {
private:
    bool speedHackEnabled;
public:
    GameSpeedCallback(IGame* game, bool speedHackEnabled);
    virtual void execute() override;
};


#endif //GRIMWALL_GAMESPEEDCALLBACK_H
