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
        void draw() override;

    private:
        std::shared_ptr<xo::XO> _xo;

        void drawRestartDialog();
        void initGame();
    };
}