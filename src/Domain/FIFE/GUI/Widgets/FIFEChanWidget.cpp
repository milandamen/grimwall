//
// Created by stephanromer on 11/30/16.
//

#include "FIFEChanWidget.h"

FIFEChanWidget::~FIFEChanWidget()
{
    delete this->widget;
}

fcn::Widget * FIFEChanWidget::getFCNWidget()
{
    return this->widget;
}

void FIFEChanWidget::setX(int x) {
    this->widget->setX(x);
}

void FIFEChanWidget::setY(int y) {
    this->widget->setY(y);
}

void FIFEChanWidget::setWidth(int width)
{
    this->widget->setWidth(width);
}

void FIFEChanWidget::setHeight(int height){
    this->widget->setHeight(height);
}