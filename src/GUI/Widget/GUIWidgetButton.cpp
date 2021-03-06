
#include "GUIWidgetButton.h"

void GUIWidgetButton::onClick(std::function<void()> delegate)
{
    this->onClickDelegate = delegate;
}

void GUIWidgetButton::onClick(std::function<void(AGUIWidget*)> delegate)
{
    this->onClickDelegateWithWidget = delegate;
}