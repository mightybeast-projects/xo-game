#pragma once

#include "screen.hpp"
#include <memory>

namespace screen
{
    struct Screen;

    struct ScreenManager
    {
        void switchTo(std::unique_ptr<screen::Screen> screen);
        void draw();

    private:
        std::unique_ptr<screen::Screen> _current;
    };
}