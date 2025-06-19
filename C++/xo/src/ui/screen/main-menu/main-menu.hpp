#pragma once

#include <memory>
#include "button.hpp"

namespace screen
{
    struct MainMenuScreen
    {
        MainMenuScreen();

        void draw();

    private:
        std::unique_ptr<widget::Button> _startBtn;
    };
}