#pragma once

#include "screen-manager.hpp"
#include <memory>
#include "drawable.hpp"
#include <vector>

namespace screen
{
    struct ScreenManager;

    struct Screen : utils::Drawable
    {
        inline void setScreenManager(ScreenManager *sm)
        {
            _sm = sm;
        }

        inline virtual void draw()
        {
            for (auto &w : _widgets)
                w->draw();
        }

    protected:
        screen::ScreenManager *_sm;
        std::vector<std::unique_ptr<utils::Drawable>> _widgets;
    };
}