//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_FIFECHANIMAGE_H
#define GRIMWALL_FIFECHANIMAGE_H


#include "FIFEChanWidget.h"
#include <fifechan/sdl/sdlimageloader.hpp>
#include <fifechan/image.hpp>
#include <fifechan/widgets/icon.hpp>

class FIFEChanImage : public FIFEChanWidget
{
    //static SDLImageLoader* imageLoader {nullptr};

private:
    fcn::Image* image {nullptr};
    fcn::Icon* icon {nullptr};

public:
    FIFEChanImage();
    ~FIFEChanImage();
    void setAsset(std::string);
    void setCaption(std::string) override {};
};


#endif //GRIMWALL_FIFECHANIMAGE_H
