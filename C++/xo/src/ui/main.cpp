#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"

bool showMessageBox = false;
Color bgColor = RED;

int main()
{
    InitWindow(400, 400, "XOGame");
    SetTargetFPS(60);

    GuiButton((Rectangle){100, 200, 120, 30}, "#191#Show Message");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(bgColor);

        DrawLine(0, 0, 300, 500, GREEN);

        if (GuiButton((Rectangle){24, 24, 120, 30}, "#191#Show Message"))
            showMessageBox = true;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            bgColor = GREEN;

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            bgColor = YELLOW;

        if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
            bgColor = RED;

        if (showMessageBox)
        {
            int result = GuiMessageBox(
                (Rectangle){85, 70, 250, 100},
                "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

            if (result >= 0)
                showMessageBox = false;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}