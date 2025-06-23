#pragma once

#include "raylib.h"
#include "config.hpp"
#include "drawable.hpp"

namespace widget
{
    struct X : common::Drawable
    {
        X(int x, int y, int size) : _x(x), _y(y), _size(size) {}

        inline void draw()
        {
            DrawText("x", _x, _y - _size / 3.3, _size, PRIMARY);
        }

        inline int width()
        {
            return MeasureText("x", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}