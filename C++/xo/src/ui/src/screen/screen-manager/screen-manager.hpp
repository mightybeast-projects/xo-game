#pragma once

#include "screen.hpp"
#include <memory>
#include "drawable.hpp"

namespace screen
{
    struct Screen;

    struct ScreenManager : common::Drawable
    {
        void switchTo(std::unique_ptr<screen::Screen> screen);
        void draw(const gfx::Renderer &renderer) const override;

    private:
        std::unique_ptr<screen::Screen> _current;
    };
}