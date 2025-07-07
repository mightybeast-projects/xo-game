#pragma once

#include "screen.hpp"
#include "xo-value.hpp"
#include <memory>
#include "types.hpp"

namespace mock
{
    struct MockScreen : screen::Screen
    {
        MockScreen()
        {
            const Col color = {0, 0, 0, 0};

            auto widget = std::make_unique<widget::XOValue>("x", 0, 0, 100, color);

            _widgets.push_back(std::move(widget));
        }

        const screen::ScreenManager *screenManager()
        {
            return _screenManager;
        }
    };
}