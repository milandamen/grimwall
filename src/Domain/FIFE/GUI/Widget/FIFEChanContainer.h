
#ifndef GRIMWALL_FIFECHANCONTAINER_H
#define GRIMWALL_FIFECHANCONTAINER_H

#include <fifechan/widgets/container.hpp>
#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetContainer.h"

class FIFEChanContainer : public AFIFEChanWidget, public GUIWidgetContainer {
private:
    fcn::Container* container {nullptr};

public:
    FIFEChanContainer();
    ~FIFEChanContainer();

    fcn::Widget* getWidget() override;

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

    void addWidget(AGUIWidget* widget, int x, int y) override;
    void removeWidget(AGUIWidget* widget) override;

    virtual void setForegroundColor(int r, int g, int b, int a) override;
    virtual void setBackgroundColor(int r, int g, int b, int a) override;
};


#endif //GRIMWALL_FIFECHANCONTAINER_H
