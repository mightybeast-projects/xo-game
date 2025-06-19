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

        void draw();

    private:
        std::unique_ptr<widget::Button> _startBtn;
        std::unique_ptr<widget::XOGrid> _grid;
    };
}