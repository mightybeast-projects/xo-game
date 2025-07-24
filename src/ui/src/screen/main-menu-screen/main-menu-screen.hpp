#pragma once

#include "button.hpp"
#include "renderer.hpp"
#include "screen.hpp"
#include <memory>

namespace screen
{
    struct MainMenuScreen : Screen
    {
        MainMenuScreen();

    private:
        void initLogo();
        void initPlayButton();
    };
}