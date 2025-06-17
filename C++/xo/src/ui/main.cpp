#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "button.hpp"
#include "config.hpp"

using namespace element;

int main()
{
    InitWindow(WIDTH, HEIGHT, "XOGame");
    SetTargetFPS(TARGET_FPS);

    Button showBtn = Button((Rectangle){100, 200, 120, 30}, "#191#Show Message");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BG);

        DrawLine(0, 0, 300, 500, GREEN);

        showBtn.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}