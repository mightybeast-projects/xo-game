#pragma once

#include "button.hpp"

namespace screen
{
    struct GameScreen
    {
        GameScreen() { init(); };

        void draw();

    private:
        widget::Button btn;

        void init();
    };
}