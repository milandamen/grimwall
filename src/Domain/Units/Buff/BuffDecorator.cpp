#include "BuffDecorator.h"

BuffDecorator::BuffDecorator(IUnit *next, int duration)
    : next{next}, duration{duration}
{
    this->next->setPrevious(this);
}

BuffDecorator::~BuffDecorator() { }

std::string BuffDecorator::getName() {
    return this->next->getName();
}

double BuffDecorator::getReach() {
    return this->next->getReach();
}

int BuffDecorator::getAttackDelay() {
    return this->next->getAttackDelay();
}

int BuffDecorator::getPower() {
    return this->next->getPower();
}

int BuffDecorator::getHitPoints() {
    return this->next->getHitPoints();
}

double BuffDecorator::getSpeed()
{
    return this->next->getSpeed();
}

int BuffDecorator::getVisibility()
{
    return this->next->getVisibility();
}

void BuffDecorator::receiveDamage(int power) {
    this->next->receiveDamage(power);
}

double BuffDecorator::getX() {
    return this->next->getX();
}

void BuffDecorator::setX(double x) {
    this->next->setX(x);
}

double BuffDecorator::getY() {
    return this->next->getY();
}

void BuffDecorator::setY(double y) {
    this->next->setY(y);
}

void BuffDecorator::setNext(IUnit *next) {
    this->next = next;
}

void BuffDecorator::setPrevious(IUnit *previous) {
    this->previous = previous;
}

void BuffDecorator::tick() {
    this->next->tick();

    if (++this->time >= this->duration){
        this->next->setPrevious(this->previous);
        this->previous->setNext(this->next);
        delete this;
    }
}