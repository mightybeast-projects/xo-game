#pragma once

#include "button.hpp"
#include "xo-grid.hpp"

namespace screen
{
    struct GameScreen
    {
        GameScreen()
        {
            init();
        };

        void draw();

    private:
        widget::Button _startBtn;
        widget::XOGrid *_grid;

        void init();
    };
}