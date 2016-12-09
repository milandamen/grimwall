#include "MoveCallback.h"

MoveCallback::MoveCallback(IGame* game, std::string direction)
    : KeypressCallback(game, 1), direction{direction}
{
    
}

void MoveCallback::execute() {
    if (!shouldExecute()) { return; }
    
    if (direction == "UP")
    {
        up();
    }
    else if (direction == "RIGHT")
    {
        right();
    }
    else if (direction == "DOWN")
    {
        down();
    }
    else if (direction == "LEFT")
    {
        left();
    }
    else if (direction == "UPRIGHT")
    {
        upright();
    }
    else if (direction == "RIGHTDOWN")
    {
        rightdown();
    }
    else if (direction == "DOWNLEFT")
    {
        downleft();
    }
    else if (direction == "LEFTUP")
    {
        leftup();
    }

    EngineFacade::engine()->setInstanceLocation("Dralas", this->game->getHero()->getX(), this->game->getHero()->getY());
}

void MoveCallback::up() {
    // Diagonal speed is 1/3 slower in both directions because moving over 2 axles
    this->game->getHero()->setX(this->game->getHero()->getX() + (double)this->game->getHero()->getSpeed() / 133);
    this->game->getHero()->setY(this->game->getHero()->getY() - (double)this->game->getHero()->getSpeed() / 133);
}

void MoveCallback::left() {
    this->game->getHero()->setX(this->game->getHero()->getX() - (double)this->game->getHero()->getSpeed() / 133);
    this->game->getHero()->setY(this->game->getHero()->getY() - (double)this->game->getHero()->getSpeed() / 133);
}

void MoveCallback::right() {
    this->game->getHero()->setX(this->game->getHero()->getX() + (double)this->game->getHero()->getSpeed() / 133);
    this->game->getHero()->setY(this->game->getHero()->getY() + (double)this->game->getHero()->getSpeed() / 133);
}

void MoveCallback::down() {
    this->game->getHero()->setX(this->game->getHero()->getX() - (double)this->game->getHero()->getSpeed() / 133);
    this->game->getHero()->setY(this->game->getHero()->getY() + (double)this->game->getHero()->getSpeed() / 133);
}

void MoveCallback::upright()
{
    this->game->getHero()->setX(this->game->getHero()->getX() + (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::rightdown()
{
    this->game->getHero()->setY(this->game->getHero()->getY() + (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::downleft()
{
    this->game->getHero()->setX(this->game->getHero()->getX() - (double)this->game->getHero()->getSpeed() / 100);
}

void MoveCallback::leftup()
{
    this->game->getHero()->setY(this->game->getHero()->getY() - (double)this->game->getHero()->getSpeed() / 100);
}

