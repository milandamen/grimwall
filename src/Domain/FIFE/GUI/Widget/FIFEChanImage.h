//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_FIFECHANIMAGE_H
#define GRIMWALL_FIFECHANIMAGE_H

#include "AFIFEChanWidget.h"
#include "../../../../GUI/Widget/GUIWidgetImage.h"
#include <fifechan/sdl/sdlimageloader.hpp>
#include <fifechan/image.hpp>
#include <fifechan/widgets/icon.hpp>

class FIFEChanImage : public AFIFEChanWidget, public GUIWidgetImage
{
private:
    fcn::Image* image {nullptr};
    fcn::Icon* icon {nullptr};

public:
    FIFEChanImage();
    ~FIFEChanImage();

    fcn::Widget* getWidget() override;

    void setAsset(std::string) override;

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


#endif //GRIMWALL_FIFECHANIMAGE_H
