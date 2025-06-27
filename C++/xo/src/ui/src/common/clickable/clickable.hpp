#pragma once

#include <functional>
#include "raylib.h"
#include "rect.hpp"

namespace common
{
    struct Clickable
    {
        Clickable() = default;
        Clickable(std::function<void()> onClick) : _onClick(onClick) {};

    protected:
        std::function<void()> _onClick;

        void handleClick(Rect rect);
    };
}