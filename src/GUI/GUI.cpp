
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

void GUI::hasBecomeActive() {} // Template void, can be overridden
void GUI::hasBecomeInactive() {} // Template void, can be overridden

void GUI::setGuiManager()
{
    this->manager = manager;
}