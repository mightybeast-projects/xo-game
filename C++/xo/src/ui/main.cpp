#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "game-screen.hpp"
#include "style_cyber.h"

using namespace screen;

int main()
{
    InitWindow(WIDTH, HEIGHT, "XOGame");
    SetTargetFPS(TARGET_FPS);

    GuiLoadStyleCyber();

    GameScreen gameScreen;

    while (!WindowShouldClose())
    {
        ClearBackground(BG);
        BeginDrawing();

        gameScreen.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}