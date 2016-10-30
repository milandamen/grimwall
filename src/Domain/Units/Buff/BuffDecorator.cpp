#include "BuffDecorator.h"

BuffDecorator::BuffDecorator(IUnit *inner, int duration)
    : m_wrappee{inner}, duration{duration}
{}

std::string BuffDecorator::getName() {
    return this->m_wrappee->getName();
}

int BuffDecorator::getReach() {
    return this->m_wrappee->getReach();
}

int BuffDecorator::getAttackDelay() {
    return this->m_wrappee->getAttackDelay();
}

int BuffDecorator::getPower() {
    return this->m_wrappee->getPower();
}

int BuffDecorator::getHitPoints() {
    return this->m_wrappee->getHitPoints();
}

int BuffDecorator::getSpeed()
{
    return this->m_wrappee->getSpeed();
}

void BuffDecorator::doDamage(int power) {
    // do damage
}
