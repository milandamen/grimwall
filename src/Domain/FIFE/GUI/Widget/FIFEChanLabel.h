
#ifndef GRIMWALL_FIFECHANLABEL_H
#define GRIMWALL_FIFECHANLABEL_H

#include <fifechan/widgets/label.hpp>
#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetLabel.h"
#include "../../../../GUI/Widget/GUITextAlignment.h"

class FIFEChanLabel : public AFIFEChanWidget, public GUIWidgetLabel
{
private:
    fcn::Label* label {nullptr};

public:
    FIFEChanLabel();
    ~FIFEChanLabel();

    fcn::Widget* getWidget() override;

    void setCaption(std::string caption) override;
    void setAlignment(GUITextAlignment alignment) override;

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

    void setForegroundColor(int r, int g, int b, int a) override;
    void setBackgroundColor(int r, int g, int b, int a) override;
};


#endif //GRIMWALL_FIFECHANLABEL_H
