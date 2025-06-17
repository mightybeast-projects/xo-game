#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "button.hpp"
#include "config.hpp"

using namespace screen;
using namespace widget;
using namespace std;

float cellSize = WIDTH / 3;

void GameScreen::init()
{
    float btnWidth = 120;
    float btnHeight = 30;

    auto btnRect = (Rectangle){
        WIDTH / 2 - btnWidth / 2,
        WIDTH / 2 - btnHeight / 2,
        btnWidth,
        btnHeight};
    _startBtn = Button(btnRect, GuiIconText(ICON_PLAYER_PLAY, "Start Game"));

    _x = X(100, 100, cellSize / 2);
    _o = O(50, 50, cellSize / 4);
}

void GameScreen::draw()
{
    _x.draw();
    _o.draw();

    DrawLine(cellSize, 0, cellSize, WIDTH, CELL);
    DrawLine(cellSize * 2, 0, cellSize * 2, WIDTH, CELL);

    DrawLine(0, cellSize, WIDTH, cellSize, CELL);
    DrawLine(0, cellSize * 2, WIDTH, cellSize * 2, CELL);

    _startBtn.draw();
}