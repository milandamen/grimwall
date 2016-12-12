//
// Created by stephanromer on 11/30/16.
//

#include "FIFEChanGuiManager.h"

FIFEChanGuiManager::FIFEChanGuiManager()
{
    this->container = new fcn::Container();

    this->bgColor.a = 0;
    this->bgColor.r = 0;
    this->bgColor.g = 0;
    this->bgColor.b = 0;

    this->container->setBackgroundColor(this->bgColor);
    this->container->setBaseColor(this->bgColor);
    this->container->setFocusable(false);

    this->container->setX(0);
    this->container->setY(0);
    this->container->setWidth(800);
    this->container->setHeight(600);
}

FIFEChanGuiManager::~FIFEChanGuiManager()
{
    delete this->container;
}

fcn::Container* FIFEChanGuiManager::getContainer()
{
    return this->container;
}

GUIWidgetButton* FIFEChanGuiManager::addButton(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanButton* button = new FIFEChanButton();
    button->setX(x);
    button->setY(y);
    button->setWidth(300);
    button->setHeight(200);
    button->setCaption(caption);
    this->widgets.push_back(button);
    this->container->add(button->getWidget());

    return button;
}

GUIWidgetLabel* FIFEChanGuiManager::addLabel(std::string caption = "", int x = 0, int y = 0)
{
    FIFEChanLabel* label = new FIFEChanLabel();
    label->setX(x);
    label->setY(y);
    label->setCaption(caption);

    this->widgets.push_back(label);
    this->container->add(label->getWidget());

    return label;
}

GUIWidgetImage* FIFEChanGuiManager::addImage(std::string asset = "", int x = 0, int y = 0)
{
    FIFEChanImage* image = new FIFEChanImage();
    image->setX(x);
    image->setY(y);
    image->setAsset(asset);

    this->widgets.push_back(image);
    this->container->add(image->getWidget());

    return image;
}