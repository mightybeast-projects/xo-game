#pragma once

#include "screen-manager.hpp"
#include <memory>
#include "drawable.hpp"

namespace screen
{
    struct ScreenManager;

    struct Screen : utils::Drawable
    {
        inline void setScreenManager(ScreenManager *sm)
        {
            _sm = sm;
        }

    protected:
        screen::ScreenManager *_sm;
    };
}