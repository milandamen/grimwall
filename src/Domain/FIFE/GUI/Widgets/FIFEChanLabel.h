//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_FIFECHANLABEL_H
#define GRIMWALL_FIFECHANLABEL_H


#include <fifechan/widgets/label.hpp>
#include "FIFEChanButton.h"
#include "../../../../GUI/Widget/GUIWidgetLabel.h"

class FIFEChanLabel : public GUIWidgetLabel
{
private:
    fcn::Label* label {nullptr};

public:
    FIFEChanLabel();
    ~FIFEChanLabel();

    void setX(int x = 0) override;
    void setY(int y = 0) override;
    void setWidth(int width = 0) override;
    void setHeight(int height = 0) override;
    fcn::Widget* getWidget();

    void setCaption(std::string caption) override;
};


#endif //GRIMWALL_FIFECHANLABEL_H
