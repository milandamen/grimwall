
#include "FIFEChanImage.h"

FIFEChanImage::FIFEChanImage()
{
    this->icon = new fcn::Icon();
}

FIFEChanImage::~FIFEChanImage()
{
    if(this->image != nullptr) {
        this->image->free();
        delete this->image;
    }

    delete this->icon;
}

int FIFEChanImage::getX()
{
    return this->icon->getX();
}

void FIFEChanImage::setX(int x) {
    this->icon->setX(x);
}

int FIFEChanImage::getY()
{
    return this->icon->getY();
}

void FIFEChanImage::setY(int y) {
    this->icon->setY(y);
}

int FIFEChanImage::getWidth()
{
    return this->icon->getWidth();
}

void FIFEChanImage::setWidth(int width)
{
    this->icon->setWidth(width);
}

int FIFEChanImage::getHeight()
{
    return this->icon->getHeight();
}

void FIFEChanImage::setHeight(int height){
    this->icon->setHeight(height);
}

bool FIFEChanImage::isVisible()
{
    return this->icon->isVisible();
}

void FIFEChanImage::setVisible(bool visible)
{
    this->icon->setVisible(visible);
}

fcn::Widget* FIFEChanImage::getWidget() {
    return this->icon;
}

void FIFEChanImage::setAsset(std::string asset)
{
    this->image = fcn::Image::load(asset, false);
    this->icon->setImage(this->image);
}

void FIFEChanImage::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 255)
{
    this->icon->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanImage::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 255)
{
    this->icon->setBackgroundColor(fcn::Color(r, g, b, a));
}
