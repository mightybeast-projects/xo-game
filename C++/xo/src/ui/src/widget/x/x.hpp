#pragma once

#include "drawable.hpp"
#include "renderer.hpp"

namespace widget
{
    struct X : common::Drawable
    {
        X(int x, int y, int size) : _x(x), _y(y), _size(size) {}

        inline void draw(const gfx::Renderer &renderer) override
        {
            const Col color = {99, 141, 219, 255};

            renderer.drawText("x", _x, _y - _size / 3.3, _size, color);
        }

        inline int width(const gfx::Renderer &renderer)
        {
            return renderer.measureText("x", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}