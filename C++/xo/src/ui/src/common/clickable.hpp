#pragma once

#include <functional>
#include "raylib.h"
#include "types.hpp"
#include "drawable.hpp"
#include "renderer.hpp"
#include <memory.h>

namespace common
{
    struct Clickable
    {
        Clickable(const std::function<void()> &onClick) : _onClick(onClick) {};

        void onClick(std::function<void()> onClick)
        {
            _onClick = onClick;
        }

        void click()
        {
            _onClick();
        }

    protected:
        std::function<void()> _onClick;

        void handleLeftClick(Rect rect, const gfx::Renderer &renderer) const
        {
            renderer.handleLeftClick(rect, _onClick);
        }
    };
}