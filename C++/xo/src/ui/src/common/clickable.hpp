#pragma once

#include <functional>
#include "raylib.h"
#include "types.hpp"
#include "drawable.hpp"
#include "renderer.hpp"
#include <memory.h>

namespace common
{
    struct Clickable : common::Drawable
    {
        Clickable(
            std::shared_ptr<gfx::Renderer> renderer,
            std::function<void()> onClick) : common::Drawable(renderer),
                                             _onClick(onClick) {};

    protected:
        std::function<void()> _onClick;

        void checkLeftClick(Rect rect)
        {
            _renderer->handleLeftClick(rect, _onClick);
        }
    };
}