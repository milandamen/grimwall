//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_FIFECHANIMAGE_H
#define GRIMWALL_FIFECHANIMAGE_H


#include "../../../../GUI/Widget/GUIWidgetImage.h"
#include <fifechan/sdl/sdlimageloader.hpp>
#include <fifechan/image.hpp>
#include <fifechan/widgets/icon.hpp>

class FIFEChanImage : public GUIWidgetImage
{
    //static SDLImageLoader* imageLoader {nullptr};

private:
    fcn::Image* image {nullptr};
    fcn::Icon* icon {nullptr};

public:
    FIFEChanImage();
    ~FIFEChanImage();

    void setX(int x = 0) override;
    void setY(int y = 0) override;
    void setWidth(int width = 0) override;
    void setHeight(int height = 0) override;
    fcn::Widget* getWidget();

    void setAsset(std::string);
};


#endif //GRIMWALL_FIFECHANIMAGE_H
