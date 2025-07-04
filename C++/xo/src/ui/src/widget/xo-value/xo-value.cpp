#include "xo-value.hpp"

void widget::XOValue::draw(const gfx::Renderer &renderer)
{
    renderer.drawText(_text, _x, _y - _size / 3.3, _size, _color);
}