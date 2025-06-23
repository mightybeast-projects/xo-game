#pragma once

#include "xo.hpp"
#include "drawable.hpp"
#include "raylib.h"
#include "config.hpp"
#include <optional>

namespace widget
{
    struct Cell : common::Drawable
    {
        Cell() {};
        Cell(float x, float y, int size, std::optional<xo::XOValue> value)
            : _x(x), _y(y), _size(size), _value(value) {}

        void draw()
        {
            DrawRectangleRounded(
                {_x, _y, (float)_size, (float)_size},
                0.1,
                0,
                BG_SECONDARY);
        }

    private:
        float _x;
        float _y;
        int _size;
        std::optional<xo::XOValue> _value;
    };
}