#include "x.hpp"

void widget::X::draw(const gfx::Renderer &renderer)
{
    const Col color = {99, 141, 219, 255};

    renderer.drawText("x", _x, _y - _size / 3.3, _size, color);
}