
#ifndef GRIMWALL_FIFECHANBUTTON_H
#define GRIMWALL_FIFECHANBUTTON_H


#include <string>
#include <fifechan/mouselistener.hpp>
#include <fifechan/widgets/button.hpp>
#include <fifechan/actionevent.hpp>
#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetButton.h"

class FIFEChanButton : public AFIFEChanWidget, public GUIWidgetButton, fcn::MouseListener//, fcn::KeyListener
{
private:
    fcn::Button* button {nullptr};
    //void mouseClicked(fcn::MouseEvent& mouseEvent) override;
    void mousePressed(fcn::MouseEvent& mouseEvent) override;
    //void mouseReleased(fcn::MouseEvent& mouseEvent) override;
    //void keyPressed(fcn::KeyEvent& keyEvent) override;
    //void keyReleased(fcn::KeyEvent& keyEvent) override;

public:
    FIFEChanButton();
    ~FIFEChanButton();

    fcn::Widget* getWidget() override;

    void setCaption(std::string caption) override;

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

    virtual void setForegroundColor(int r, int g, int b, int a) override;
    virtual void setBackgroundColor(int r, int g, int b, int a) override;
    virtual void setHighlightColor(int r, int g, int b, int a) override;
};


#endif //GRIMWALL_FIFECHANBUTTON_H
