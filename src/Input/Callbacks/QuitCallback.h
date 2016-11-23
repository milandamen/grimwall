#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"

class QuitCallback : public KeypressCallback
{
public:
    QuitCallback(IGame* game);
    virtual void execute() override;
};