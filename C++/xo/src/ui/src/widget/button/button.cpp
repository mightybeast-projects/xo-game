#include "button.hpp"
#include "raygui.h"

void widget::Button::draw()
{
    Rectangle rect = {_rect.x, _rect.y, _rect.width, _rect.height};
    GuiButton(rect, _text.c_str());

    handleClick(_rect);
}
