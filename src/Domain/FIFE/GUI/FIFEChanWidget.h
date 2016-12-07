//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_FIFECHANWIDGET_H
#define GRIMWALL_FIFECHANWIDGET_H

#include "../../../GUI/Widget/GuiWidgetButton.h"

class FIFEChanWidget : public GuiWidgetButton {

protected:
    fcn::Widget* widget;

public:
    FIFEChanWidget(fcn::Widget* widget);
    ~FIFEChanWidget();

    fcn::Widget* getFCNWidget();
};


#endif //GRIMWALL_FIFECHANWIDGET_H
