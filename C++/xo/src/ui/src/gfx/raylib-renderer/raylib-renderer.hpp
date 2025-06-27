#pragma once

#include "raylib.h"
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
    };
}