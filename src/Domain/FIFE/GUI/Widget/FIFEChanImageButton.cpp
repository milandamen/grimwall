
#include "FIFEChanImageButton.h"

FIFEChanImageButton::FIFEChanImageButton()
{
    this->imageButton = new fcn::ImageButton();
    this->imageButton->addMouseListener(this);
    this->setForegroundColor(0,0,0,0); // Transparent
    this->setBackgroundColor(0,0,0,0); // Transparent
}

FIFEChanImageButton::~FIFEChanImageButton()
{
    if(this->image != nullptr) {
        this->image->free();
        delete this->image;
    }

    delete this->imageButton;
}

int FIFEChanImageButton::getX()
{
    return this->imageButton->getX();
}

void FIFEChanImageButton::setX(int x) {
    this->imageButton->setX(x);
}

int FIFEChanImageButton::getY()
{
    return this->imageButton->getY();
}

void FIFEChanImageButton::setY(int y) {
    this->imageButton->setY(y);
}

int FIFEChanImageButton::getWidth()
{
    return this->imageButton->getWidth();
}

void FIFEChanImageButton::setWidth(int width)
{
    this->imageButton->setWidth(width);
}

int FIFEChanImageButton::getHeight()
{
    return this->imageButton->getHeight();
}

void FIFEChanImageButton::setHeight(int height){
    this->imageButton->setHeight(height);
}

bool FIFEChanImageButton::isVisible()
{
    return this->imageButton->isVisible();
}

void FIFEChanImageButton::setVisible(bool visible)
{
    this->imageButton->setVisible(visible);
}

fcn::Widget* FIFEChanImageButton::getWidget() {
    return this->imageButton;
}

void FIFEChanImageButton::mousePressed(fcn::MouseEvent &mouseEvent)
{
    this->onClickDelegate();
    this->onClickDelegateWithWidget(this);
}

void FIFEChanImageButton::setCaption(std::string asset)
{
    this->imageButton->setCaption(asset);
}

void FIFEChanImageButton::setAsset(std::string asset)
{
    this->image = fcn::Image::load(asset, false);
    this->imageButton->setImage(this->image);
}

void FIFEChanImageButton::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 255)
{
    this->imageButton->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanImageButton::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 255)
{
    this->imageButton->setBackgroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanImageButton::setHighlightColor(int r = 0, int g = 0, int b = 0, int a = 255)
{
    this->imageButton->setSelectionColor(fcn::Color(r, g, b, a));
}

