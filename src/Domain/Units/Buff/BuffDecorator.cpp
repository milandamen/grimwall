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

int BuffDecorator::getVisibility()
{
    return this->m_wrappee->getSpeed();
}

void BuffDecorator::receiveDamage(int power) {
    this->m_wrappee->receiveDamage(power);
}

double BuffDecorator::getX() {
    return this->m_wrappee->getX();
}

void BuffDecorator::setX(double x) {
    this->m_wrappee->setX(x);
}

double BuffDecorator::getY() {
    return this->m_wrappee->getY();
}

void BuffDecorator::setY(double y) {
    this->m_wrappee->setY(y);
}
