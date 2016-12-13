//
// Created by stephanromer on 12/7/16.
//

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

void FIFEChanImage::setX(int x) {
    this->icon->setX(x);
}

void FIFEChanImage::setY(int y) {
    this->icon->setY(y);
}

void FIFEChanImage::setWidth(int width)
{
    this->icon->setWidth(width);
}

void FIFEChanImage::setHeight(int height){
    this->icon->setHeight(height);
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
