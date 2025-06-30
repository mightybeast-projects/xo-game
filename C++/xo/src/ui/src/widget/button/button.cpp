#include "button.hpp"

void widget::Button::draw()
{
    _renderer->drawGuiButton(_rect, _text);

    checkLeftClick(_rect);
}
