#pragma once

#include "config.hpp"
#include "drawable.hpp"
#include "renderer.hpp"
#include <memory>

namespace widget
{
    struct O : common::Drawable
    {
        O(int x,
          int y,
          int size,
          gfx::Renderer *renderer) : _x(x),
                                     _y(y),
                                     _size(size),
                                     common::Drawable(renderer) {}

        inline void draw() override
        {
            Col color = {255, 150, 69, 255};

            _renderer->drawText("o", _x, _y - _size / 3.3, _size, color);
        }

        inline int width()
        {
            return _renderer->measureText("o", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}