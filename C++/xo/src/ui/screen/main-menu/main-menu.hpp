#pragma once

#include <memory>
#include "button.hpp"
#include "screen.hpp"

namespace screen
{
    struct MainMenuScreen : Screen
    {
        MainMenuScreen();

        void draw();

    private:
        std::unique_ptr<widget::Button> _startBtn;
    };
}