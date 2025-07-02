#include "o.hpp"

void widget::O::draw(const gfx::Renderer &renderer)
{
    const Col color = {255, 150, 69, 255};

    renderer.drawText("o", _x, _y - _size / 3.3, _size, color);
}

int widget::O::width(const gfx::Renderer &renderer)
{
    return renderer.measureText("o", _size);
}