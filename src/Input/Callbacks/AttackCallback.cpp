

#include "AttackCallback.h"

AttackCallback::AttackCallback(IGame *game)
    : KeypressCallback(game, 0)
{}

void AttackCallback::execute() {
    std::cout << "Do damage";
}