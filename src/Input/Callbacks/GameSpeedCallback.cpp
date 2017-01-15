
#include "GameSpeedCallback.h"
#include "../../Domain/EngineFacade.h"

GameSpeedCallback::GameSpeedCallback(int limit)
    : KeypressCallback(game, 0), limit{limit}
{}

void GameSpeedCallback::execute() {
    if (!shouldExecute()) { return; }

    EngineFacade::engine()->setFPSLimit(limit);
}
