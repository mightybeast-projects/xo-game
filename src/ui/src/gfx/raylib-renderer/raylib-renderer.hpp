#pragma once

#include "renderer.hpp"

namespace gfx
{
    struct RaylibRenderer : gfx::Renderer
    {
        void initGameWindow() const override;
        void draw(std::function<void()> onDraw) const override;
        void closeGameWindow() const override;
        int drawGuiButton(Rect rect, std::string text) const override;

        int drawGuiMessageBox(Rect rect,
            std::string title,
            std::string message,
            std::string buttons) const override;

        void drawText(std::string text,
            int x,
            int y,
            int fontSize,
            Col color) const override;

        void drawRectangleRounded(Rect rect,
            float roundness,
            int segments,
            Col color) const override;

        void handleLeftClick(Rect r,
            std::function<void()> onClick) const override;
    };
}