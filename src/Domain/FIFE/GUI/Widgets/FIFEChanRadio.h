//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_FIFECHANRADIO_H
#define GRIMWALL_FIFECHANRADIO_H

#include <fifechan/widgets/label.hpp>
#include "FIFEChanButton.h"
#include "../../../../GUI/Widget/GUIWidgetRadio.h"

class FIFEChanRadio : public GUIWidgetRadio, fcn::MouseListener {
private:
    fcn::RadioButton* radio {nullptr};
    void mousePressed(fcn::MouseEvent& mouseEvent) override;

public:
    FIFEChanRadio();
    ~FIFEChanRadio();

    fcn::Widget* getWidget();

    void setCaption(std::string caption) override;
    void setGroup(std::string group) override;
    void setSelected(bool selected) override;

    void setX(int x = 0) override;
    void setY(int y = 0) override;
    void setWidth(int width = 0) override;
    void setHeight(int height = 0) override;

    virtual void onClick(std::function<void()> delegate) override;
    virtual void setForegroundColor(int r, int g, int b, int a) override;
    virtual void setBackgroundColor(int r, int g, int b, int a) override;
};


#endif //GRIMWALL_FIFECHANRADIO_H
