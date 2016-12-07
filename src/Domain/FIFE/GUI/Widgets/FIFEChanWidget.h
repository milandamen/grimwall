//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_FIFECHANWIDGET_H
#define GRIMWALL_FIFECHANWIDGET_H

#include <fifechan/widget.hpp>
#include "../../../../GUI/Widget/GUIWidgetButton.h"


class FIFEChanWidget : public GUIWidgetButton {

protected:
    fcn::Widget* widget;

public:
    virtual ~FIFEChanWidget() = 0;

    void setWidth(int width) override;
    void setHeight(int height) override;

    void setX(int x) override;
    void setY(int y) override;

    fcn::Widget* getFCNWidget();
};


#endif //GRIMWALL_FIFECHANWIDGET_H
