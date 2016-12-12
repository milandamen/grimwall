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