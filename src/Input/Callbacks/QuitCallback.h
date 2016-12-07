#include "../KeypressCallback.h"
#include "../../Domain/IGame.h"

class QuitCallback : public KeypressCallback
{
public:
    /**
     * Create a QuitCallback object
     * 
     * @param game An instance of IGame that the callback can execute methods on
     */
    QuitCallback(IGame* game);
    virtual void execute() override;
};