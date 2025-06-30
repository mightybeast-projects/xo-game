#pragma once

#include <functional>
#include <string>
#include "types.hpp"

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

        virtual void drawText(const std::string text,
                              const int posX,
                              const int posY,
                              const int fontSize,
                              Col color) = 0;

        virtual int measureText(const std::string text, int fontSize) = 0;

        virtual void drawRectangleRounded(const Rect rec,
                                          const float roundness,
                                          const int segments,
                                          const Col color) = 0;

        virtual void handleLeftClick(Rect r, std::function<void()> onClick) = 0;
    };
}