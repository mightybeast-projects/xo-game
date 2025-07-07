#pragma once

#include <memory>
#include "button.hpp"
#include "screen.hpp"
#include "renderer.hpp"

namespace screen
{
    struct MainMenuScreen : Screen
    {
        MainMenuScreen();

    private:
        std::unique_ptr<widget::Button> _startBtn;

        void initLogo();
        void initPlayButton();
    };
}