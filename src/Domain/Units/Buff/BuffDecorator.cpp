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

void BuffDecorator::setInvincible(bool invincible)
{
    this->next->setInvincible(invincible);
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

bool BuffDecorator::attack() {
    return this->next->attack();
}

void BuffDecorator::tick() {
    this->next->tick();

    // increment the buff time per tick by 1, then check if the duration has passed
    if (++this->time >= this->duration){
        // if the buff has expired, detach the buff from the linked list and self destruct
        this->next->setPrevious(this->previous);
        this->previous->setNext(this->next);
        this->updateStatsListener();
        delete this;
    }
}

void BuffDecorator::setStatsListener(std::function<void()> delegate) {
    this->updateStatsListener = delegate;
    this->next->setStatsListener(delegate);
}

bool BuffDecorator::canAttack() {
    return this->next->canAttack();
}

void BuffDecorator::setInvisible(bool invisible) {
    this->next->setInvisible(invisible);
}
