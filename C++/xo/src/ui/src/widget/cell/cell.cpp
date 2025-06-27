#include "cell.hpp"
#include <optional>
#include "x.hpp"
#include "o.hpp"

widget::Cell::Cell(
    float x,
    float y,
    int size,
    std::optional<xo::XOValue> value,
    std::function<void()> onClick) : _x(x),
                                     _y(y),
                                     _size(size),
                                     common::Clickable(onClick)
{
    _rect = {_x, _y, (float)_size, (float)_size};

    if (!value.has_value())
        return;

    setDrawable(value.value());
}

void widget::Cell::draw()
{
    DrawRectangleRounded(_rect, 0.1, 0, BG_SECONDARY);

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
    const auto x = _x + _size / 3.75;
    const auto y = _y + _size / 3.75;

    if (value == xo::XOValue::X)
        _drawableValue = std::make_shared<widget::X>(x, y, _size);

    if (value == xo::XOValue::O)
        _drawableValue = std::make_shared<widget::O>(x, y, _size);
}
