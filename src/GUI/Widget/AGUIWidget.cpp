//
// Created by stephanromer on 11/30/16.
//

#include "AGUIWidget.h"

std::string AGUIWidget::getIdentifier()
{
    return this->identifier;
}

void AGUIWidget::setIdentifier(std::string identifier)
{
    this->identifier = identifier;
}