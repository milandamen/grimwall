//
// Created by stephanromer on 11/30/16.
//

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

void FIFEChanButton::onClick(std::function<void()> delegate) {
    this->onClickDelegate = delegate;
}

void FIFEChanButton::setX(int x) {
    this->button->setX(x);
}

void FIFEChanButton::setY(int y) {
    this->button->setY(y);
}

void FIFEChanButton::setWidth(int width)
{
    this->button->setWidth(width);
}

void FIFEChanButton::setHeight(int height){
    this->button->setHeight(height);
}

fcn::Widget* FIFEChanButton::getWidget() {
    return this->button;
}

//void FIFEChanButton::mouseClicked(fcn::MouseEvent &mouseEvent)
//{
//    this->onClickDelegate();
//}

void FIFEChanButton::mousePressed(fcn::MouseEvent &mouseEvent)
{
    //std::cout << "JA!" << std::endl;
    this->onClickDelegate();
}

//void FIFEChanButton::mouseReleased(fcn::MouseEvent &mouseEvent)
//{
//    this->onClickDelegate();
//}