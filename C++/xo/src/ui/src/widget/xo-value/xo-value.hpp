#pragma once

#include "drawable.hpp"
#include "renderer.hpp"
#include "types.hpp"
#include <string>

namespace widget
{
    struct XOValue : common::Drawable
    {
        XOValue(std::string text, int x, int y, int size, Col color)
            : _text(text), _x(x), _y(y), _size(size), _color(color) {};

        void draw(const gfx::Renderer &renderer) const override;

    private:
        std::string _text;
        int _x;
        int _y;
        int _size;
        Col _color;
    };
}