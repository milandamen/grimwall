//
// Created by stephanromer on 11/30/16.
//

#include "FIFEChanGuiManager.h"

FIFEChanGuiManager::FIFEChanGuiManager()
{
    this->container = new fcn::Container();
}

FIFEChanGuiManager::~FIFEChanGuiManager()
{
    delete this->container;
}

fcn::Container* FIFEChanGuiManager::getContainer()
{
    return this->container;
}

FIFEChanButton* FIFEChanGuiManager::addButton(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanButton* button = new FIFEChanButton();
    button->setX(x);
    button->setY(y);
    button->setWidth(300);
    button->setHeight(200);
    button->setCaption(caption);
    this->widgets.push_back(button);
    this->container->add(button->getFCNWidget());

    return button;
}

FIFEChanLabel* FIFEChanGuiManager::addLabel(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanLabel* label = new FIFEChanLabel();
    label->setX(x);
    label->setY(y);
    label->setCaption(caption);

    this->widgets.push_back(label);
    this->container->add(label->getFCNWidget());

    return label;
}

FIFEChanImage* FIFEChanGuiManager::addImage(std::string asset = "", int x = 0, int y = 0)
{
    FIFEChanImage* image = new FIFEChanImage();
    image->setX(x);
    image->setY(y);
    image->setAsset(asset);

    this->widgets.push_back(image);
    this->container->add(image->getFCNWidget());

    return image;
}

void FIFEChanGuiManager::action(const fcn::ActionEvent &actionEvent)
{}

void FIFEChanGuiManager::keyPressed(fcn::KeyEvent &keyEvent)
{}