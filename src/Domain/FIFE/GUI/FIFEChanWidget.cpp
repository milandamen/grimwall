//
// Created by stephanromer on 11/30/16.
//

#include "FIFEChanWidget.h"

FIFEChanWidget::FIFEChanWidget(fcn::Widget widget)
    : widget{}
{}

FIFEChanWidget::~FIFEChanWidget()
{
    delete this->widget;
}

fcn::Widget * FIFEChanWidget::getFCNWidget()
{
    return this->widget;
}