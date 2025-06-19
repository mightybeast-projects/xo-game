#pragma once

#include "screen-manager.hpp"
#include <memory>

namespace screen
{
    struct ScreenManager;

    struct Screen
    {
        virtual void draw() = 0;

        inline void setScreenManager(ScreenManager *sm)
        {
            _sm = sm;
        }

    protected:
        screen::ScreenManager *_sm;
    };
}