#pragma once

#include <functional>
#include <string>
#include "types.hpp"

namespace gfx
{
    struct Renderer
    {
        virtual void initGameWindow() const = 0;
        virtual void draw(std::function<void()> onDraw) const = 0;
        virtual void closeGameWindow() const = 0;

        virtual int drawGuiButton(Rect rect, std::string text) const = 0;

        virtual int drawGuiMessageBox(Rect rect,
                                      std::string title,
                                      std::string message,
                                      std::string buttons) const = 0;

        virtual void drawText(std::string text,
                              int posX,
                              int posY,
                              int fontSize,
                              Col color) const = 0;

        virtual void drawRectangleRounded(Rect rec,
                                          float roundness,
                                          int segments,
                                          Col color) const = 0;

        virtual void handleLeftClick(
            Rect r,
            std::function<void()> onClick) const = 0;
    };
}