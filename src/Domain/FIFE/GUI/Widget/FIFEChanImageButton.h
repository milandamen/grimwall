
#ifndef GRIMWALL_FIFECHANIMAGEBUTTON_H
#define GRIMWALL_FIFECHANIMAGEBUTTON_H

#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetImage.h"
#include "../../../../GUI/Widget/GUIWidgetButton.h"
#include <fifechan/sdl/sdlimageloader.hpp>
#include <fifechan/image.hpp>
#include <fifechan/widgets/imagebutton.hpp>

class FIFEChanImageButton : public AFIFEChanWidget, public GUIWidgetImage, public GUIWidgetButton {
private:
    fcn::Image* image {nullptr};
    fcn::ImageButton* imageButton {nullptr};

public:
    FIFEChanImageButton();
    ~FIFEChanImageButton();

    fcn::Widget* getWidget() override;

    void setAsset(std::string) override;
    void setCaption(std::string) override;

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
    void setHighlightColor(int r, int g, int b, int a) override;
};

#endif //GRIMWALL_FIFECHANIMAGEBUTTON_H
