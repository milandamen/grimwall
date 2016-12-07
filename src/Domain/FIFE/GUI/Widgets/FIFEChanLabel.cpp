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

void FIFEChanLabel::setCaption(std::string caption)
{
    this->label->setCaption(caption);
}