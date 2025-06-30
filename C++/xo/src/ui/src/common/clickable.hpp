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
        Clickable(std::function<void()> onClick) : _onClick(onClick) {};

    protected:
        std::function<void()> _onClick;

        void checkLeftClick(Rect rect, const gfx::Renderer &renderer)
        {
            renderer.handleLeftClick(rect, _onClick);
        }
    };
}