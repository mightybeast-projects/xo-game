#include "cell.hpp"
#include <optional>

void widget::Cell::draw(const gfx::Renderer &renderer) const
{
    const Rect rect = {_rect.x, _rect.y, _rect.width, _rect.height};
    const Col color = {56, 56, 56, 255};

    renderer.drawRectangleRounded(rect, 0.1, 0, color);

    if (_drawableValue.has_value())
        _drawableValue->get()->draw(renderer);

    handleLeftClick(_rect, renderer);
}

void widget::Cell::setValue(xo::XOValue value)
{
    const auto x = _rect.x + _rect.width / 3.75;
    const auto y = _rect.y + _rect.width / 3.75;

    if (value == xo::XOValue::X)
        _drawableValue = std::make_unique<widget::XOValue>(
            "x", x, y, _rect.width, (Col){99, 141, 219, 255});

    if (value == xo::XOValue::O)
        _drawableValue = std::make_unique<widget::XOValue>(
            "o", x, y, _rect.width, (Col){255, 150, 69, 255});
}
