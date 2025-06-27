#pragma once

#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "renderer.hpp"
#include "style_cyber.h"
#include <functional>

namespace gfx
{
    struct RaylibRenderer : gfx::Renderer
    {
        void initGameWindow() override
        {
            InitWindow(WIDTH, WIDTH, "XOGame");
            SetTargetFPS(60);
            GuiLoadStyleCyber();
        }

        void draw(const std::function<void()> onDraw) override
        {
            Color bg = {46, 46, 46, 255};

            while (!WindowShouldClose())
            {
                ClearBackground(bg);
                BeginDrawing();

                onDraw();

                EndDrawing();
            }
        }

        void closeGameWindow() override
        {
            CloseWindow();
        }

        int drawGuiButton(const Rect rect, const std::string text) override
        {
            return GuiButton({rect.x, rect.y, rect.width, rect.height}, text.c_str());
        }

        int drawGuiMessageBox(
            const Rect rect,
            const std::string title,
            const std::string message,
            const std::string buttons) override
        {
            return GuiMessageBox(
                {rect.x, rect.y, rect.width, rect.height},
                title.c_str(),
                message.c_str(),
                buttons.c_str());
        }

        void drawText(const std::string text,
                      const int x,
                      const int y,
                      const int fontSize,
                      Col color) override
        {
            return DrawText(
                text.c_str(),
                x,
                y,
                fontSize,
                {color.r, color.g, color.b, color.a});
        }

        int measureText(const std::string text, int fontSize) override
        {
            return MeasureText(text.c_str(), fontSize);
        }
    };
}