#pragma once

#include "renderer.hpp"
#include <memory>

namespace common
{
    struct Drawable
    {
        virtual void draw(const gfx::Renderer &renderer) = 0;
    };
}