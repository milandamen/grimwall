//
// Created by stephanromer on 11/30/16.
//

#include "FIFEChanButton.h"

FIFEChanButton::FIFEChanButton()
{
    this->widget = new fcn::Button();
    this->widget->addMouseListener(this);
}

FIFEChanButton::~FIFEChanButton()
{
    delete this->button;
}

void FIFEChanButton::setCaption(std::string caption)
{
    this->button->setCaption(caption);
}

void FIFEChanButton::mousePressed(fcn::MouseEvent &mouseEvent)
{
    this->onClickDelegate();
}