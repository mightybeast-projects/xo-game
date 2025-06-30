#pragma once

#include "renderer.hpp"
#include <memory>

namespace common
{
    struct Drawable
    {
        Drawable(gfx::Renderer *renderer) : _renderer(renderer) {}

        virtual void draw() = 0;

    protected:
        gfx::Renderer *_renderer;
    };
}