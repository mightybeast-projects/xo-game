#pragma once

#include "button.hpp"
#include "xo-grid.hpp"
#include <memory>

namespace screen
{
    struct GameScreen
    {
        GameScreen();

        void draw();

    private:
        std::unique_ptr<widget::Button> _startBtn;
        std::unique_ptr<widget::XOGrid> _grid;
    };
}