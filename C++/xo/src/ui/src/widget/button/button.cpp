#include "button.hpp"

void widget::Button::draw(const gfx::Renderer &renderer)
{
    renderer.drawGuiButton(_rect, _text);

    checkLeftClick(_rect, renderer);
}
