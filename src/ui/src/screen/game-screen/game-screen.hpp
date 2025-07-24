#pragma once

#include "button.hpp"
#include "restart-dialog.hpp"
#include "screen.hpp"
#include "xo-grid.hpp"
#include <memory>

namespace screen
{
    struct GameScreen : Screen
    {
        GameScreen();

    private:
        std::unique_ptr<xo::XO> _xo;

        void initRestartDialog();
    };
}