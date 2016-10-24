#include "BuffDecorator.h"

BuffDecorator::BuffDecorator(IUnit *inner)
    : m_wrappee{inner}
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

void BuffDecorator::doDamage(int power) {
    // do damage
}