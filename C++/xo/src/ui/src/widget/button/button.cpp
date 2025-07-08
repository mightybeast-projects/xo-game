#include "button.hpp"

void widget::Button::draw(const gfx::Renderer &renderer) const
{
    renderer.drawGuiButton(_rect, _text);

    handleLeftClick(_rect, renderer);
}
