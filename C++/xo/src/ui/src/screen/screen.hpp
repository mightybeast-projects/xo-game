#pragma once

#include "screen-manager.hpp"
#include <memory>
#include "drawable.hpp"
#include <vector>
#include "renderer.hpp"

namespace screen
{
    struct ScreenManager;

    struct Screen : common::Drawable
    {
        Screen(std::shared_ptr<gfx::Renderer> renderer) : common::Drawable(renderer) {}

        inline void setScreenManager(ScreenManager *screenManager)
        {
            _screenManager = screenManager;
        }

        inline void draw() override
        {
            for (auto &w : _widgets)
                w->draw();
        }

    protected:
        screen::ScreenManager *_screenManager;
        std::shared_ptr<gfx::Renderer> _renderer;
        std::vector<std::unique_ptr<common::Drawable>> _widgets;
    };
}