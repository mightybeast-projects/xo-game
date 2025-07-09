#pragma once

#include "clickable.hpp"
#include "config.hpp"
#include "drawable.hpp"
#include "types.hpp"
#include "xo-value.hpp"
#include "xo.hpp"
#include <memory>
#include <optional>

namespace widget
{
    struct Cell : common::Clickable, common::Drawable
    {
        Cell(Rect rect) : _rect(rect), common::Clickable(nullptr) { }

        Cell(Rect rect, xo::XOValue value)
            : _rect(rect), common::Clickable(nullptr)
        {
            setValue(value);
        }

        Cell(Rect rect, xo::XOValue value, std::function<void()> onClick)
            : _rect(rect), common::Clickable(onClick)
        {
            setValue(value);
        }

        void draw(const gfx::Renderer& renderer) const override;
        void setValue(xo::XOValue value);

    private:
        const Rect _rect;

        std::optional<std::unique_ptr<widget::XOValue>> _drawableValue;
    };
}