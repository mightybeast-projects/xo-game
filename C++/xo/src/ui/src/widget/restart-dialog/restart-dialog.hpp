#pragma once

#include "drawable.hpp"
#include "xo.hpp"
#include <functional>

namespace widget
{
    struct RestartDialog : public common::Drawable
    {
        RestartDialog(xo::XO *xo) : _xo(xo) {}

        void onRestart(std::function<void()> onRestart)
        {
            _onRestart = onRestart;
        }

        void onQuit(std::function<void()> onQuit)
        {
            _onQuit = onQuit;
        }

        void draw(const gfx::Renderer &renderer) const override;

    private:
        xo::XO *const _xo;

        std::function<void()> _onRestart;
        std::function<void()> _onQuit;
    };
}
