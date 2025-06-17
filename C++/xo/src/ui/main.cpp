#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "game-screen.hpp"

using namespace screen;

int main()
{
    InitWindow(WIDTH, HEIGHT, "XOGame");
    SetTargetFPS(TARGET_FPS);

    GameScreen game;

    while (!WindowShouldClose())
    {
        ClearBackground(BG);
        BeginDrawing();

        game.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}