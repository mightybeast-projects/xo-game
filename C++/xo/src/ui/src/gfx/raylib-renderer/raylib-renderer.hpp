#pragma once

#include "renderer.hpp"

namespace gfx
{
    struct RaylibRenderer : gfx::Renderer
    {
        void initGameWindow() override;
        void draw(const std::function<void()> onDraw) override;
        void closeGameWindow() override;
        int drawGuiButton(const Rect rect, const std::string text) override;

        int drawGuiMessageBox(
            const Rect rect,
            const std::string title,
            const std::string message,
            const std::string buttons) override;

        void drawText(const std::string text,
                      const int x,
                      const int y,
                      const int fontSize,
                      Col color) override;

        int measureText(const std::string text, int fontSize) override;

        void drawRectangleRounded(const Rect rect,
                                  const float roundness,
                                  const int segments,
                                  const Col color) override;

        void handleLeftClick(const Rect r, const std::function<void()> onClick) override;
    };
}