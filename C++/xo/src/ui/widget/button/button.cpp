#include "button.hpp"
#include "raygui.h"

using namespace widget;

void Button::draw()
{
    GuiButton(_rect, _text.c_str());
}
