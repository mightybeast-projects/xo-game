#pragma once

#include <functional>
#include <string>
#include "types.hpp"

namespace gfx
{
    struct Renderer
    {
        virtual void initGameWindow() const = 0;
        virtual void draw(const std::function<void()> onDraw) const = 0;
        virtual void closeGameWindow() const = 0;

        virtual int drawGuiButton(const Rect rect, const std::string text) const = 0;

        virtual int drawGuiMessageBox(const Rect rect,
                                      const std::string title,
                                      const std::string message,
                                      const std::string buttons) const = 0;

        virtual void drawText(const std::string text,
                              const int posX,
                              const int posY,
                              const int fontSize,
                              Col color) const = 0;

        virtual int measureText(const std::string text, int fontSize) const = 0;

        virtual void drawRectangleRounded(const Rect rec,
                                          const float roundness,
                                          const int segments,
                                          const Col color) const = 0;

        virtual void handleLeftClick(
            const Rect r,
            const std::function<void()> onClick) const = 0;
    };
}