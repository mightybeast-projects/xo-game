#include "cell.hpp"
#include <optional>
#include "x.hpp"
#include "o.hpp"

widget::Cell::Cell(
    Rect rect,
    std::optional<xo::XOValue> value,
    std::function<void()> onClick) : _rect(rect),
                                     common::Clickable(onClick)
{
    if (!value.has_value())
        return;

    setDrawable(value.value());
}

void widget::Cell::draw()
{
    Rectangle rect = {_rect.x, _rect.y, _rect.width, _rect.height};
    DrawRectangleRounded(rect, 0.1, 0, BG_SECONDARY);

    if (_drawableValue.has_value())
        _drawableValue->get()->draw();

    handleClick(_rect);
}

void widget::Cell::setValue(xo::XOValue value)
{
    setDrawable(value);
}

void widget::Cell::setDrawable(xo::XOValue value)
{
    const auto x = _rect.x + _rect.width / 3.75;
    const auto y = _rect.y + _rect.width / 3.75;

    if (value == xo::XOValue::X)
        _drawableValue = std::make_shared<widget::X>(x, y, _rect.width);

    if (value == xo::XOValue::O)
        _drawableValue = std::make_shared<widget::O>(x, y, _rect.width);
}
