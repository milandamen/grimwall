//
// Created by stephanromer on 12/7/16.
//

#include "FIFEChanLabel.h"

FIFEChanLabel::FIFEChanLabel()
{
    this->label = new fcn::Label();
}

FIFEChanLabel::~FIFEChanLabel()
{
    delete this->label;
}

void FIFEChanLabel::setX(int x) {
    this->label->setX(x);
}

void FIFEChanLabel::setY(int y) {
    this->label->setY(y);
}

void FIFEChanLabel::setWidth(int width)
{
    this->label->setWidth(width);
}

void FIFEChanLabel::setHeight(int height){
    this->label->setHeight(height);
}

fcn::Widget* FIFEChanLabel::getWidget() {
    return this->label;
}

void FIFEChanLabel::setCaption(std::string caption)
{
    this->label->setCaption(caption);
}

void FIFEChanLabel::setAlignment(GUITextAlignment alignment)
{
    switch(alignment) {
        case GUITextAlignment::Left:
            this->label->setAlignment(fcn::Graphics::Alignment::Left);
            break;
        case GUITextAlignment::Center:
            this->label->setAlignment(fcn::Graphics::Alignment::Center);
            break;
        case GUITextAlignment::Right:
            this->label->setAlignment(fcn::Graphics::Alignment::Right);
            break;
    }
}

void FIFEChanLabel::setForegroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->label->setForegroundColor(fcn::Color(r, g, b, a));
}

void FIFEChanLabel::setBackgroundColor(int r = 0, int g = 0, int b = 0, int a = 0)
{
    this->label->setBaseColor(fcn::Color(r, g, b, a));
    this->label->setBackgroundColor(fcn::Color(r, g, b, a));
}