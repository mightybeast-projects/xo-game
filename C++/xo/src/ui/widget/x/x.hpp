#pragma once

#include "raylib.h"
#include "config.hpp"

namespace widget
{
    struct X
    {
        X(int x, int y, int size) : _x(x), _y(y), _size(size) {}

        inline void draw()
        {
            DrawLine(_x, _y, _x + _size, _y + _size, CROSS);
            DrawLine(_x + _size, _y, _x, _y + _size, CROSS);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}