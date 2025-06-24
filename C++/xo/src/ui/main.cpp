#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "game-screen.hpp"
#include "style_cyber.h"
#include "screen-manager.hpp"
#include "main-menu.hpp"
#include <iostream>

int main()
{
    InitWindow(WIDTH, WIDTH, "XOGame");
    SetTargetFPS(TARGET_FPS);

    GuiLoadStyleCyber();

    screen::ScreenManager sm;

    sm.switchTo(new screen::MainMenuScreen());

    while (!WindowShouldClose())
    {
        ClearBackground(BG);
        BeginDrawing();

        sm.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}