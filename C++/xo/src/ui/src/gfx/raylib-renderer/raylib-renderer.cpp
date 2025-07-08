#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "style_cyber.h"
#include <functional>
#include "raylib-renderer.hpp"

void gfx::RaylibRenderer::initGameWindow() const
{
    InitWindow(WIDTH, WIDTH, "XOGame");
    SetTargetFPS(60);
    GuiLoadStyleCyber();
}

void gfx::RaylibRenderer::draw(const std::function<void()> onDraw) const
{
    const Color bg = {46, 46, 46, 255};

    while (!WindowShouldClose())
    {
        ClearBackground(bg);
        BeginDrawing();

        onDraw();

        EndDrawing();
    }
}

void gfx::RaylibRenderer::closeGameWindow() const
{
    CloseWindow();
}

int gfx::RaylibRenderer::drawGuiButton(Rect rect, std::string text) const
{
    return GuiButton({rect.x, rect.y, rect.width, rect.height}, text.c_str());
}

int gfx::RaylibRenderer::drawGuiMessageBox(Rect rect,
                                           std::string title,
                                           std::string message,
                                           std::string buttons) const
{
    const Rectangle r = {rect.x, rect.y, rect.width, rect.height};

    return GuiMessageBox(r, title.c_str(), message.c_str(), buttons.c_str());
}

void gfx::RaylibRenderer::drawText(std::string text,
                                   int x,
                                   int y,
                                   int fontSize,
                                   Col color) const
{
    const Color c = {color.r, color.g, color.b, color.a};

    return DrawText(text.c_str(), x, y, fontSize, c);
}

void gfx::RaylibRenderer::drawRectangleRounded(Rect rect,
                                               float roundness,
                                               int segments,
                                               Col color) const
{
    const Rectangle r = {rect.x, rect.y, rect.width, rect.height};
    const Color c = {color.r, color.g, color.b, color.a};

    return DrawRectangleRounded(r, roundness, segments, c);
}

void gfx::RaylibRenderer::handleLeftClick(Rect r, std::function<void()> onClick) const
{
    if (onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        const Vector2 mousePos = GetMousePosition();
        const Rectangle rect = {r.x, r.y, r.width, r.height};

        if (CheckCollisionPointRec(mousePos, rect))
            onClick();
    }
}