//
// Created by stephanromer on 12/14/16.
//

#include "FIFEChanRadio.h"


FIFEChanRadio::FIFEChanRadio()
{
    this->radio = new fcn::RadioButton();
    this->radio->addMouseListener(this);
}

FIFEChanRadio::~FIFEChanRadio()
{
    delete this->radio;
}

void FIFEChanRadio::setCaption(std::string caption)
{
    this->radio->setCaption(caption);
}

void FIFEChanRadio::setGroup(std::string group)
{
    this->radio->setGroup(group);
}

void FIFEChanRadio::setSelected(bool selected)
{
    this->radio->setSelected(selected);
}

void FIFEChanRadio::onClick(std::function<void()> delegate)
{
    this->onClickDelegate = delegate;
}

int FIFEChanRadio::getX()
{
    return this->radio->getX();
}

void FIFEChanRadio::setX(int x)
{
    this->radio->setX(x);
}

int FIFEChanRadio::getY()
{
    return this->radio->getY();
}

void FIFEChanRadio::setY(int y)
{
    this->radio->setY(y);
}

int FIFEChanRadio::getWidth()
{
    return this->radio->getWidth();
}

void FIFEChanRadio::setWidth(int width)
{
    this->radio->setWidth(width);
}

int FIFEChanRadio::getHeight()
{
    return this->radio->getHeight();
}

void FIFEChanRadio::setHeight(int height)
{
    this->radio->setHeight(height);
}

bool FIFEChanRadio::isVisible()
{
    return this->radio->isVisible();
}

void FIFEChanRadio::setVisible(bool visible)
{
    this->radio->setVisible(visible);
}

fcn::Widget* FIFEChanRadio::getWidget()
{
    return this->radio;
}

void FIFEChanRadio::mousePressed(fcn::MouseEvent &mouseEvent)
{
    this->onClickDelegate();
}

void FIFEChanRadio::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->radio->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanRadio::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->radio->setBaseColor(fcn::Color(r, g, b, a));
    this->radio->setBackgroundColor(fcn::Color(r, g, b, a));
}