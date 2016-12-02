

#include "MoveCallback.h"
#include "../../Domain/EngineFacade.h"


MoveCallback::MoveCallback(IGame* game, int firePerNFrames, std::string direction)
    : KeypressCallback(game, firePerNFrames), direction{direction}
{
    
}

void MoveCallback::execute() {
    if (!shouldExecute()) { return; }
    
    if (direction == "UP")
        up();
    else if (direction == "RIGHT")
        right();
    else if (direction == "DOWN")
        down();
    else if (direction == "LEFT")
        left();

    EngineFacade::engine()->setInstanceLocation("Dralas", this->game->getHero()->getX(), this->game->getHero()->getY());
}

void MoveCallback::up() {
    this->game->getHero()->setX(this->game->getHero()->getX() + (double)this->game->getHero()->getSpeed() / 100);
    this->game->getHero()->setY(this->game->getHero()->getY() - (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::left() {
    this->game->getHero()->setX(this->game->getHero()->getX() - (double)this->game->getHero()->getSpeed() / 100);
    this->game->getHero()->setY(this->game->getHero()->getY() - (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::right() {
    this->game->getHero()->setX(this->game->getHero()->getX() + (double)this->game->getHero()->getSpeed() / 100);
    this->game->getHero()->setY(this->game->getHero()->getY() + (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::down() {
    this->game->getHero()->setX(this->game->getHero()->getX() - (double)this->game->getHero()->getSpeed() / 100);
    this->game->getHero()->setY(this->game->getHero()->getY() + (double)this->game->getHero()->getSpeed() / 100);
}

