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
        virtual ~Screen() = default;

        inline virtual void setScreenManager(ScreenManager *screenManager)
        {
            _screenManager = screenManager;
        }

        inline void draw(const gfx::Renderer &renderer) const override
        {
            for (auto &w : _widgets)
                w->draw(renderer);
        }

    protected:
        screen::ScreenManager *_screenManager;
        std::vector<std::unique_ptr<common::Drawable>> _widgets;
    };
}