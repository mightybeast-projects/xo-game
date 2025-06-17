#pragma once

#include "button.hpp"
#include "x.hpp"
#include "o.hpp"

namespace screen
{
    struct GameScreen
    {
        GameScreen() { init(); };

        void draw();

    private:
        widget::Button btn;
        widget::X x;
        widget::O o;

        void init();
    };
}