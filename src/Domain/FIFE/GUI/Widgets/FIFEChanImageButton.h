//
// Created by stephanromer on 12/14/16.
//

#ifndef GRIMWALL_FIFECHANIMAGEBUTTON_H
#define GRIMWALL_FIFECHANIMAGEBUTTON_H

#include "../../../../GUI/Widget/GUIWidgetImage.h"
#include "../../../../GUI/Widget/GUIWidgetButton.h"
#include <fifechan/sdl/sdlimageloader.hpp>
#include <fifechan/image.hpp>
#include <fifechan/widgets/imagebutton.hpp>

class FIFEChanImageButton : public GUIWidgetImage, public GUIWidgetButton {
private:
    fcn::Image* image {nullptr};
    fcn::ImageButton* imageButton {nullptr};

public:
    FIFEChanImageButton();
    ~FIFEChanImageButton();

    fcn::Widget* getWidget();

    void setX(int x = 0) override;
    void setY(int y = 0) override;
    void setWidth(int width = 0) override;
    void setHeight(int height = 0) override;
    void setAsset(std::string) override;
    void setCaption(std::string) override;

    void setForegroundColor(int r, int g, int b, int a) override;
    void setBackgroundColor(int r, int g, int b, int a) override;
    void setHighlightColor(int r, int g, int b, int a) override;
};


//void FIFEChanImageButton::setHighlightColor()
//{}


#endif //GRIMWALL_FIFECHANIMAGEBUTTON_H
