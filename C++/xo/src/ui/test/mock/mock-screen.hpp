#pragma once

#include "screen.hpp"
#include "types.hpp"
#include "xo-value.hpp"
#include <memory>

namespace mock
{
    struct MockScreen : screen::Screen
    {
        MOCK_METHOD(void, setScreenManager, (screen::ScreenManager*));
        MOCK_METHOD(void, draw, (const gfx::Renderer&), (const, override));
    };
}