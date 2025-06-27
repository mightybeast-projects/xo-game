#include "button.hpp"

void widget::Button::draw()
{
    _renderer->drawGuiButton(_rect, _text);
    handleClick(_rect);
}
