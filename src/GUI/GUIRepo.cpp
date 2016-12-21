
#include "GUIRepo.h"

GUIRepo::GUIRepo()
{}

GUIRepo::~GUIRepo()
{
}

void GUIRepo::addGUI(std::string name, GUI *gui)
{
    this->guis[name] = gui;
}

GUI* GUIRepo::getGUI(std::string name)
{
    return this->guis[name];
}