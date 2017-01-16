
#include "GameSpeedCallback.h"
#include "../../Domain/EngineFacade.h"

GameSpeedCallback::GameSpeedCallback(IGame* game, bool speedHackEnabled)
    : KeypressCallback(game, 0), speedHackEnabled{speedHackEnabled}
{}

void GameSpeedCallback::execute() {
    if (!shouldExecute()) { return; }

    this->game->setSpeedHack(this->speedHackEnabled);
}
