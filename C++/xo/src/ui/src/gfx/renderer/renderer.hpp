#pragma once

#include <functional>

namespace gfx
{
    struct Renderer
    {
        virtual void initGameWindow() = 0;
        virtual void draw(const std::function<void()> onDraw) = 0;
        virtual void closeGameWindow() = 0;
    };
}