//
// Created by stephanromer on 12/14/16.
//

#include "FIFEChanImageButton.h"

FIFEChanImageButton::FIFEChanImageButton()
{
    this->imageButton = new fcn::ImageButton();
}

FIFEChanImageButton::~FIFEChanImageButton()
{
    if(this->image != nullptr) {
        this->image->free();
        delete this->image;
    }

    delete this->imageButton;
}

void FIFEChanImageButton::setX(int x) {
    this->imageButton->setX(x);
}

void FIFEChanImageButton::setY(int y) {
    this->imageButton->setY(y);
}

void FIFEChanImageButton::setWidth(int width)
{
    this->imageButton->setWidth(width);
}

void FIFEChanImageButton::setHeight(int height){
    this->imageButton->setHeight(height);
}

fcn::Widget* FIFEChanImageButton::getWidget() {
    return this->imageButton;
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

