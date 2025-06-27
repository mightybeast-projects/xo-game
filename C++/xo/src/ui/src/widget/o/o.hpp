#pragma once

#include "raylib.h"
#include "config.hpp"
#include "drawable.hpp"

namespace widget
{
    struct O : common::Drawable
    {
        O(int x, int y, int size) : _x(x), _y(y), _size(size) {}

        inline void draw() override
        {
            DrawText("o", _x, _y - _size / 3.3, _size, SECONDARY);
        }

        inline int width()
        {
            return MeasureText("o", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}