//
// Created by stephanromer on 11/23/16.
//

#include "MainMenu.h"

MainMenu::MainMenu(FIFE::FifechanManager *manager)
    : manager{manager}
{
    // Initialise FifeChanManager
    manager->init("OpenGL", 800, 600);

    // Set top
    fcn::Container* top = new fcn::Container();
    manager->getFifechanGUI()->setTop(top);

    // Button Campaign (Play)
    fcn::Button* btnCampaign = new fcn::Button();
    btnCampaign->setId("btnCampaign");
    btnCampaign->setActionEventId("clickBtnCampaign");
    btnCampaign->setWidth(300);
    btnCampaign->setHeight(50);
    btnCampaign->setPosition(100, 100);
    btnCampaign->setCaption("Campaign");
    top->add(btnCampaign);

    //fcn::ActionEvent* e = new fcn::ActionEvent(btnCampaign, "btnCampaign");
    //fcn::ActionListener::action(e);

    // Button Options
    fcn::Button* btnOptions = new fcn::Button();
    btnOptions->setId("btnOptions");
    btnOptions->setActionEventId("clickBtnOptions");
    btnOptions->setWidth(300);
    btnOptions->setHeight(50);
    btnOptions->setPosition(100, 200);
    btnOptions->setCaption("Options");
    top->add(btnOptions);

    // Button Exit
    fcn::Button* btnExit = new fcn::Button();
    btnExit->setId("btnExit");
    btnExit->setActionEventId("clickBtnExit");
    btnExit->setWidth(300);
    btnExit->setHeight(50);
    btnExit->setPosition(100, 300);
    btnExit->setCaption("Exit to desktop");
    top->add(btnExit);
}

void MainMenu::action(const fcn::ActionEvent& actionEvent)
{
    cout << "Event: " << actionEvent.getId();
}

MainMenu::~MainMenu()
{}
