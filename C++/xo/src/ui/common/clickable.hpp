#pragma once

#include <functional>
#include "raylib.h"

namespace common
{
    struct Clickable
    {
        inline void onClick(std::function<void()> cb)
        {
            _onClick = cb;
        }

    protected:
        std::function<void()> _onClick;

        void handleClick(Rectangle rect);
    };
}