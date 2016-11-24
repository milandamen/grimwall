

#include "MoveCallback.h"
#include "../../Domain/EngineFacade.h"


MoveCallback::MoveCallback(IGame* game, std::string direction)
    :KeypressCallback(game), direction{direction}
{}

void MoveCallback::execute() {
    if (direction == "UP")
        up();
    else if (direction == "LEFT")
        left();
    else if (direction == "RIGHT")
        right();
    else if (direction == "DOWN")
        down();

    EngineFacade::engine()->setInstanceLocation("Dralas", this->game->getHero()->getX(), this->game->getHero()->getY());
}

void MoveCallback::up() {
    this->game->getHero()->setX(this->game->getHero()->getX() + increaser);
    this->game->getHero()->setY(this->game->getHero()->getY() - increaser);
}

void MoveCallback::left() {
    this->game->getHero()->setX(this->game->getHero()->getX() - increaser);
    this->game->getHero()->setY(this->game->getHero()->getY() - increaser);
}

void MoveCallback::right() {
    this->game->getHero()->setX(this->game->getHero()->getX() + increaser);
    this->game->getHero()->setY(this->game->getHero()->getY() + increaser);
}

void MoveCallback::down() {
    this->game->getHero()->setX(this->game->getHero()->getX() - increaser);
    this->game->getHero()->setY(this->game->getHero()->getY() + increaser);
}

