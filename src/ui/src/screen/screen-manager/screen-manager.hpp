#pragma once

#include "drawable.hpp"
#include "screen.hpp"
#include <memory>

namespace screen
{
    struct Screen;

    struct ScreenManager : common::Drawable
    {
        void switchTo(std::unique_ptr<screen::Screen> screen);
        void draw(const gfx::Renderer& renderer) const override;

    private:
        std::unique_ptr<screen::Screen> _current;
    };
}