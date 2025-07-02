#pragma once

#include "drawable.hpp"
#include "renderer.hpp"

namespace widget
{
    struct O : common::Drawable
    {
        O(int x, int y, int size) : _x(x), _y(y), _size(size) {};

        void draw(const gfx::Renderer &renderer) override;
        int width(const gfx::Renderer &renderer);

    private:
        int _x;
        int _y;
        int _size;
    };
}