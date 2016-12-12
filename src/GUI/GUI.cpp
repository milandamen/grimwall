//
// Created by joost on 10/11/2016.
//

#include "GUI.h"


GUI::GUI(AGUIManager *manager)
    : manager{manager}
{}

GUI::~GUI()
{
    delete this->manager;
}

AGUIManager* GUI::getGuiManager()
{
    return this->manager;
}

void GUI::setGuiManager()
{
    this->manager = manager;
}