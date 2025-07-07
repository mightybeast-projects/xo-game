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

        void draw(const gfx::Renderer &renderer) override;

    private:
        std::unique_ptr<xo::XO> _xo;
        std::unique_ptr<widget::RestartDialog> _dialog;

        void initGame();
        void initRestartDialog();
    };
}