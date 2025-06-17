#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "config.hpp"

using namespace screen;
using namespace widget;
using namespace std;

void GameScreen::init()
{
    float btnWidth = 120;
    float btnHeight = 30;
    float btnX = WIDTH / 2 - btnWidth / 2;
    float btnY = WIDTH / 2 - btnHeight / 2;
    auto btnRect = (Rectangle){btnX, btnY, btnWidth, btnHeight};
    _startBtn = Button(btnRect, GuiIconText(ICON_PLAYER_PLAY, "Start Game"));

    _grid = new XOGrid(10);
}

void GameScreen::draw()
{
    _grid->draw();
    _startBtn.draw();
}