#pragma once

#include "button.hpp"
#include "xo-grid.hpp"
#include <memory>
#include "screen.hpp"

namespace screen
{
    struct GameScreen : Screen
    {
        GameScreen();

        void draw(const gfx::Renderer &renderer) override;

    private:
        std::unique_ptr<xo::XO> _xo;

        void initGame();
        void drawRestartDialog(const gfx::Renderer &renderer);
    };
}