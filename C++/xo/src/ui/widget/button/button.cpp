#include "button.hpp"
#include "raygui.h"

void widget::Button::draw()
{
    GuiButton(_rect, _text.c_str());

    handleClick(_rect);
}
