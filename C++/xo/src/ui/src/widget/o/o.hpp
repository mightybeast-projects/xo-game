#pragma once

#include "drawable.hpp"
#include "renderer.hpp"
#include <memory>

namespace widget
{
    struct O : common::Drawable
    {
        O(int x, int y, int size) : _x(x), _y(y), _size(size) {}

        inline void draw(const gfx::Renderer &renderer) override
        {
            Col color = {255, 150, 69, 255};

            renderer.drawText("o", _x, _y - _size / 3.3, _size, color);
        }

        inline int width(const gfx::Renderer &renderer)
        {
            return renderer.measureText("o", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}