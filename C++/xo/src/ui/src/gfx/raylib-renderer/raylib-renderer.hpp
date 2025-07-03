#pragma once

#include "renderer.hpp"

namespace gfx
{
    struct RaylibRenderer : gfx::Renderer
    {
        void initGameWindow() const override;
        void draw(const std::function<void()> onDraw) const override;
        void closeGameWindow() const override;
        int drawGuiButton(const Rect rect, const std::string text) const override;

        int drawGuiMessageBox(
            const Rect rect,
            const std::string title,
            const std::string message,
            const std::string buttons) const override;

        void drawText(const std::string text,
                      const int x,
                      const int y,
                      const int fontSize,
                      Col color) const override;

        void drawRectangleRounded(const Rect rect,
                                  const float roundness,
                                  const int segments,
                                  const Col color) const override;

        void handleLeftClick(const Rect r,
                             const std::function<void()> onClick) const override;
    };
}