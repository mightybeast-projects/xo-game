#pragma once

#include "screen.hpp"
#include "xo-value.hpp"
#include <memory>
#include "types.hpp"

namespace mock
{
    struct MockScreen : screen::Screen
    {
        MOCK_METHOD(void, setScreenManager, (screen::ScreenManager *));
        MOCK_METHOD(void, draw, (const gfx::Renderer &), (const, override));
    };
}