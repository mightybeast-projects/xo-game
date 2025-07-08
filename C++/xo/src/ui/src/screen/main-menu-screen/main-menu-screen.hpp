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
        void initLogo();
        void initPlayButton();
    };
}