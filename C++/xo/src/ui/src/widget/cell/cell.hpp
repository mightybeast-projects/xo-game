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
    struct Cell : common::Drawable, common::Clickable
    {
        Cell() : common::Drawable(nullptr) {};
        Cell(
            Rect rect,
            std::optional<xo::XOValue> value,
            std::shared_ptr<gfx::Renderer> renderer,
            std::function<void()> onClick);

        void draw() override;
        void setValue(xo::XOValue value);

    private:
        Rect _rect;
        std::optional<std::shared_ptr<common::Drawable>> _drawableValue;

        void setDrawableValue(xo::XOValue value);
    };
}