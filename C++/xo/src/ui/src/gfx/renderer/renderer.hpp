#pragma once

#include <functional>
#include <string>
#include "rect.hpp"

namespace gfx
{
    struct Renderer
    {
        virtual void initGameWindow() = 0;
        virtual void draw(const std::function<void()> onDraw) = 0;
        virtual void closeGameWindow() = 0;

        virtual int drawGuiButton(const Rect rect, const std::string text) = 0;
        virtual int drawGuiMessageBox(const Rect rect,
                                      const std::string title,
                                      const std::string message,
                                      const std::string buttons) = 0;
    };
}