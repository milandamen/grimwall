//
// Created by stephanromer on 11/30/16.
//

#ifndef GRIMWALL_FIFECHANGUIMANAGER_H
#define GRIMWALL_FIFECHANGUIMANAGER_H

#include <fifechan/actionlistener.hpp>
#include <fifechan/keylistener.hpp>
#include <fifechan/widgets/container.hpp>
#include <fifechan/widgets/button.hpp>
#include <vector>
#include "Widgets/FIFEChanButton.h"
#include "../../../GUI/AGUIManager.h"
#include "../../../GUI/Widget/AGUIWidget.h"
#include "Widgets/FIFEChanLabel.h"
#include "Widgets/FIFEChanImage.h"

class FIFEChanGuiManager : AGUIManager, fcn::ActionListener, fcn::KeyListener {

private:
    fcn::Container* container {nullptr};
    std::vector<AGUIWidget*> widgets;
    int count = 0;

public:
    FIFEChanGuiManager();
    virtual ~FIFEChanGuiManager() = 0;

    fcn::Container* getContainer();

    FIFEChanButton* addButton(std::string caption, int x, int y);
    FIFEChanLabel* addLabel(std::string caption, int x, int y);
    FIFEChanImage* addImage(std::string asset, int x, int y);

    void action(const fcn::ActionEvent& actionEvent) override;
    void keyPressed(fcn::KeyEvent& keyEvent) override;
};


#endif //GRIMWALL_FIFECHANGUIMANAGER_H
