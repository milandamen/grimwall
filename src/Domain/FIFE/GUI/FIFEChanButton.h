//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_FIFECHANBUTTON_H
#define GRIMWALL_FIFECHANBUTTON_H


#include <string>
#include <fifechan/mouselistener.hpp>
#include <fifechan/widgets/button.hpp>
#include "FIFEChanWidget.h"


class FIFEChanButton : public FIFEChanWidget, fcn::MouseListener {

private:
    fcn::Button* button;

public:
    FIFEChanButton();
    ~FIFEChanButton();

public:
    void setX(int x) override;

    void setCaption(std::string caption) override;
    void mousePressed(fcn::MouseEvent& mouseEvent) override;
};


#endif //GRIMWALL_FIFECHANBUTTON_H
