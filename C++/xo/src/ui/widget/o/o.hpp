#pragma once

#include "raylib.h"
#include "config.hpp"
#include "drawable.hpp"

namespace widget
{
    struct O : common::Drawable
    {
        O(int x, int y, int radius) : _x(x), _y(y), _radius(radius) {}

        inline void draw()
        {
            DrawCircleLines(_x, _y, _radius * 0.55, CIRCLE);
        }

    private:
        int _x;
        int _y;
        int _radius;
    };
}