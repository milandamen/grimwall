//
// Created by stephanromer on 11/30/16.
//

#include "GUIWidgetButton.h"

void GUIWidgetButton::onClick(std::function<void()> delegate)
{
    this->onClickDelegate = delegate;
}