#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "game-screen.hpp"
#include "style_cyber.h"

int main()
{
    InitWindow(WIDTH, WIDTH, "XOGame");
    SetTargetFPS(TARGET_FPS);

    GuiLoadStyleCyber();

    screen::GameScreen gameScreen;

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