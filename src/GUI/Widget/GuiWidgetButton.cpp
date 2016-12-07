//
// Created by stephanromer on 11/30/16.
//

#include "GuiWidgetButton.h"

void GuiWidgetButton::onClick(std::function<void()> delegate) {
    this->onClickDelegate = delegate;
}