#pragma once

#include "drawable.hpp"
#include "raylib.h"
#include "config.hpp"

namespace widget
{
    struct Cell : common::Drawable
    {
        Cell(float x, float y, int size) : _x(x), _y(y), _size(size) {}

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
    };
}