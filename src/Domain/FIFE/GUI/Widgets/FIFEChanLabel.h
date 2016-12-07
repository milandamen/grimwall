//
// Created by stephanromer on 12/7/16.
//

#ifndef GRIMWALL_FIFECHANLABEL_H
#define GRIMWALL_FIFECHANLABEL_H


#include <fifechan/widgets/label.hpp>
#include "FIFEChanButton.h"

class FIFEChanLabel : public FIFEChanButton
{
private:
    fcn::Label* label {nullptr};

public:
    FIFEChanLabel();
    ~FIFEChanLabel();
    void setCaption(std::string caption) override;
};


#endif //GRIMWALL_FIFECHANLABEL_H
