//
// Created by stephanromer on 1/11/17.
//

#include "GUIWidgetImageButton.h"

void GUIWidgetImageButton::onClick(std::function<void()> delegate)
{
    this->onClickDelegate = delegate;
}

void GUIWidgetImageButton::onClick(std::function<void(AGUIWidget*)> delegate)
{
    this->onClickDelegateWithWidget = delegate;
}