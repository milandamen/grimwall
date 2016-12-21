
#ifndef GRIMWALL_FIFECHANRADIO_H
#define GRIMWALL_FIFECHANRADIO_H

#include <fifechan/widgets/label.hpp>
#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetRadio.h"

class FIFEChanRadio : public AFIFEChanWidget, public GUIWidgetRadio, fcn::MouseListener {
private:
    fcn::RadioButton* radio {nullptr};
    void mousePressed(fcn::MouseEvent& mouseEvent) override;

public:
    FIFEChanRadio();
    ~FIFEChanRadio();

    fcn::Widget* getWidget() override;

    void setCaption(std::string caption) override;
    void setGroup(std::string group) override;
    void setSelected(bool selected) override;

    int getX() override;
    void setX(int x = 0) override;
    int getY() override;
    void setY(int y = 0) override;
    int getWidth() override;
    void setWidth(int width = 0) override;
    int getHeight() override;
    void setHeight(int height = 0) override;
    bool isVisible() override;
    void setVisible(bool visible) override;

    virtual void onClick(std::function<void()> delegate) override;
    virtual void setForegroundColor(int r, int g, int b, int a) override;
    virtual void setBackgroundColor(int r, int g, int b, int a) override;
};


#endif //GRIMWALL_FIFECHANRADIO_H
