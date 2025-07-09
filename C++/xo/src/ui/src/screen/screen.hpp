#pragma once

#include "drawable.hpp"
#include "renderer.hpp"
#include "screen-manager.hpp"
#include <memory>
#include <vector>

namespace screen
{
    struct ScreenManager;

    struct Screen : common::Drawable
    {
        virtual ~Screen() = default;

        inline virtual void setScreenManager(ScreenManager* screenManager)
        {
            _screenManager = screenManager;
        }

        inline void draw(const gfx::Renderer& renderer) const override
        {
            for (auto& w : _widgets)
                w->draw(renderer);
        }

    protected:
        screen::ScreenManager* _screenManager;
        std::vector<std::unique_ptr<common::Drawable>> _widgets;
    };
}