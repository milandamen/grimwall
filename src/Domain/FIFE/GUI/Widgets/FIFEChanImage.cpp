//
// Created by stephanromer on 12/7/16.
//

#include "FIFEChanImage.h"

FIFEChanImage::FIFEChanImage()
{
    //if(FIFEChanImage::imageLoader == nullptr)
    //    FIFEChanImage::imageLoader = new SDLImageLoader();
    //this->image->setImageLoader(FIFEChanImage::imageLoader);

    this->icon = new fcn::Icon();
}

FIFEChanImage::~FIFEChanImage()
{
    if(this->image != nullptr) {
        this->image->free();
        delete this->image;
    }

    delete this->icon;
}

void FIFEChanImage::setAsset(std::string asset)
{
    this->image = fcn::Image::load(asset, false);
    this->icon->setImage(this->image);
}