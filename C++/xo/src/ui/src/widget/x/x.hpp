#pragma once

#include "config.hpp"
#include "drawable.hpp"
#include "renderer.hpp"

namespace widget
{
    struct X : common::Drawable
    {
        X(int x,
          int y,
          int size,
          gfx::Renderer *renderer) : _x(x),
                                     _y(y),
                                     _size(size),
                                     common::Drawable(renderer) {}

        inline void draw() override
        {
            const Col color = {99, 141, 219, 255};

            _renderer->drawText("x", _x, _y - _size / 3.3, _size, color);
        }

        inline int width()
        {
            return _renderer->measureText("x", _size);
        }

    private:
        int _x;
        int _y;
        int _size;
    };
}