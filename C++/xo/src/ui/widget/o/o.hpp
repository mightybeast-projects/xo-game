#pragma once

#include "raylib.h"
#include "config.hpp"

namespace widget
{
    struct O
    {
        O() {}
        O(int x, int y, int radius) : _x(x), _y(y), _radius(radius) {}

        inline void draw()
        {
            DrawCircleLines(_x, _y, _radius * 1.3, CIRCLE);
        }

    private:
        int _x;
        int _y;
        int _radius;
    };
}