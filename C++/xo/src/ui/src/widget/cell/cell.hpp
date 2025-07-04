#pragma once

#include "xo.hpp"
#include "drawable.hpp"
#include "config.hpp"
#include <optional>
#include <memory>
#include "clickable.hpp"
#include "types.hpp"
#include "drawable.hpp"

namespace widget
{
    struct Cell : common::Clickable, common::Drawable
    {
        Cell(const Rect rect) : _rect(rect), common::Clickable(nullptr) {}

        Cell(const Rect rect,
             const xo::XOValue value) : _rect(rect), common::Clickable(nullptr)
        {
            setValue(value);
        }

        Cell(const Rect rect,
             const xo::XOValue value,
             const std::function<void()> onClick) : _rect(rect),
                                                    common::Clickable(onClick)
        {
            setValue(value);
        }

        void draw(const gfx::Renderer &renderer) override;
        void setValue(const xo::XOValue value);

    private:
        Rect _rect;
        std::optional<std::unique_ptr<common::Drawable>> _drawableValue;
    };
}