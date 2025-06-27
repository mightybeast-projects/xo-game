#pragma once

#include "renderer.hpp"
#include <memory>

namespace common
{
    struct Drawable
    {
        Drawable(std::shared_ptr<gfx::Renderer> renderer) : _renderer(renderer) {}

        virtual void draw() = 0;

    protected:
        std::shared_ptr<gfx::Renderer> _renderer;
    };
}