#pragma once

#include <functional>
#include "raylib.h"
#include "types.hpp"

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