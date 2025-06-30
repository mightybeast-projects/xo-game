#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "style_cyber.h"
#include <functional>
#include "raylib-renderer.hpp"

void gfx::RaylibRenderer::initGameWindow()
{
    InitWindow(WIDTH, WIDTH, "XOGame");
    SetTargetFPS(60);
    GuiLoadStyleCyber();
}

void gfx::RaylibRenderer::draw(const std::function<void()> onDraw)
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

void gfx::RaylibRenderer::closeGameWindow()
{
    CloseWindow();
}

int gfx::RaylibRenderer::drawGuiButton(const Rect rect, const std::string text)
{
    return GuiButton({rect.x, rect.y, rect.width, rect.height}, text.c_str());
}

int gfx::RaylibRenderer::drawGuiMessageBox(
    const Rect rect,
    const std::string title,
    const std::string message,
    const std::string buttons)
{
    Rectangle r = {rect.x, rect.y, rect.width, rect.height};

    return GuiMessageBox(r, title.c_str(), message.c_str(), buttons.c_str());
}

void gfx::RaylibRenderer::drawText(const std::string text,
                                   const int x,
                                   const int y,
                                   const int fontSize,
                                   Col color)
{
    Color c = {color.r, color.g, color.b, color.a};

    return DrawText(text.c_str(), x, y, fontSize, c);
}

int gfx::RaylibRenderer::measureText(const std::string text, int fontSize)
{
    return MeasureText(text.c_str(), fontSize);
}

void gfx::RaylibRenderer::drawRectangleRounded(const Rect rect,
                                               const float roundness,
                                               const int segments,
                                               const Col color)
{
    Rectangle r = {rect.x, rect.y, rect.width, rect.height};
    Color c = {color.r, color.g, color.b, color.a};

    return DrawRectangleRounded(r, roundness, segments, c);
}

void gfx::RaylibRenderer::handleLeftClick(
    const Rect r,
    const std::function<void()> onClick)
{
    if (onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        const Vector2 mousePos = GetMousePosition();
        const Rectangle rect = {r.x, r.y, r.width, r.height};

        if (CheckCollisionPointRec(mousePos, rect))
            onClick();
    }
}