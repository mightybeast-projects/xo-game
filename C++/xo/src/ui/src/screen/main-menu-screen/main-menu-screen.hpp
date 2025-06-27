#pragma once

#include <memory>
#include "button.hpp"
#include "screen.hpp"
#include "renderer.hpp"

namespace screen
{
    struct MainMenuScreen : Screen
    {
        MainMenuScreen(std::shared_ptr<gfx::Renderer> renderer);

        void draw() override;

    private:
        std::unique_ptr<widget::Button> _startBtn;

        void drawLogo();
        void drawStartButton();
    };
}