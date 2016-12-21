
#include "FIFEChanButton.h"

FIFEChanButton::FIFEChanButton()
{
    this->button = new fcn::Button();
    this->button->addMouseListener(this);
}

FIFEChanButton::~FIFEChanButton()
{
    delete this->button;
}

void FIFEChanButton::setCaption(std::string caption)
{
    this->button->setCaption(caption);
}

int FIFEChanButton::getX()
{
    return this->button->getX();
}

void FIFEChanButton::setX(int x) {
    this->button->setX(x);
}

int FIFEChanButton::getY()
{
    return this->button->getY();
}

void FIFEChanButton::setY(int y) {
    this->button->setY(y);
}

int FIFEChanButton::getWidth()
{
    return this->button->getWidth();
}

void FIFEChanButton::setWidth(int width)
{
    this->button->setWidth(width);
}

int FIFEChanButton::getHeight()
{
    return this->button->getHeight();
}

void FIFEChanButton::setHeight(int height){
    this->button->setHeight(height);
}

bool FIFEChanButton::isVisible(){
    return this->button->isVisible();
}

void FIFEChanButton::setVisible(bool visible)
{
    this->button->setVisible(visible);
}

fcn::Widget* FIFEChanButton::getWidget() {
    return this->button;
}

void FIFEChanButton::mousePressed(fcn::MouseEvent &mouseEvent)
{
    this->onClickDelegate();
    this->onClickDelegateWithWidget(this);
}

void FIFEChanButton::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->button->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanButton::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->button->setBaseColor(fcn::Color(r, g, b, a));
    this->button->setBackgroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanButton::setHighlightColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->button->setSelectionColor(fcn::Color(r, g, b, a));
}