#pragma once

#include "xo.hpp"
#include "drawable.hpp"
#include "raylib.h"
#include "config.hpp"
#include <optional>
#include <memory>
#include "clickable.hpp"

namespace widget
{
    struct Cell : common::Drawable, common::Clickable
    {
        Cell() = default;
        Cell(
            float x,
            float y,
            int size,
            std::optional<xo::XOValue> value,
            std::function<void()> onClick);

        void draw();
        void setValue(xo::XOValue value);

    private:
        float _x;
        float _y;
        int _size;
        Rectangle _rect;
        std::optional<std::shared_ptr<common::Drawable>> _drawable;

        void setDrawable(xo::XOValue value);
    };
}