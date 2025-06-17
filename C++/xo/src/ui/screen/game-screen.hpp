#pragma once

#include "button.hpp"
#include "x.hpp"
#include "o.hpp"

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
        widget::X _x;
        widget::O _o;

        void init();
    };
}