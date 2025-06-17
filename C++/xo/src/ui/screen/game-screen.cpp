#include "raylib.h"
#include "game-screen.hpp"
#include "button.hpp"
#include "config.hpp"

using namespace screen;
using namespace widget;

void GameScreen::init()
{
    btn = Button((Rectangle){WIDTH / 2 - 120 / 2, HEIGHT / 2 - 30 / 2, 120, 30}, "#191#Start Game");
}

void GameScreen::draw()
{
    DrawLine(0, 0, 10, 10, CROSS);
    DrawLine(10, 0, 0, 10, CROSS);

    DrawGrid(4, 2);

    DrawCircleLines(20, 20, 50, CIRCLE);

    btn.draw();
}