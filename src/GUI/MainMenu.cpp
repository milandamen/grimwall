//
// Created by stephanromer on 11/23/16.
//

#include "MainMenu.h"
#include "Widget/GUIWidgetButton.h"

MainMenu::MainMenu(AGUIManager* manager)
        : GUI(manager)
{
    GUIWidgetButton* b = manager->addButton();
    b->setX(0);
    b->setY(0);
    b->setCaption("Click me!");
    b->setWidth(300);
    b->setHeight(100);
    b->onClick([&](){
        this->ClickMeClick();
    });
}

MainMenu::~MainMenu()
{}


void MainMenu::ClickMeClick()
{

}