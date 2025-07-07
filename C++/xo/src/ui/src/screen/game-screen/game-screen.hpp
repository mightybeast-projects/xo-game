#pragma once

#include "button.hpp"
#include "xo-grid.hpp"
#include <memory>
#include "screen.hpp"
#include "restart-dialog.hpp"

namespace screen
{
    struct GameScreen : Screen
    {
        GameScreen();

    private:
        std::unique_ptr<xo::XO> _xo;

        std::unique_ptr<widget::RestartDialog> initRestartDialog();
        std::unique_ptr<widget::XOGrid> initGrid(widget::RestartDialog *dialog);
    };
}