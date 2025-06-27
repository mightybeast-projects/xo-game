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
            SetTargetFPS(TARGET_FPS);
            GuiLoadStyleCyber();
        }

        void draw(const std::function<void()> onDraw) override
        {
            while (!WindowShouldClose())
            {
                ClearBackground(BG);
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
    };
}