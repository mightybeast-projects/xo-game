#pragma once

#include <memory>
#include "button.hpp"
#include "screen.hpp"

namespace screen
{
    struct MainMenuScreen : Screen
    {
        MainMenuScreen();

        void draw() override;

    private:
        std::unique_ptr<widget::Button> _startBtn;

        void drawLogo();
        void drawStartButton();
    };
}