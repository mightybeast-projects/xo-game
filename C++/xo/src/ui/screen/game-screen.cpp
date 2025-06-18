#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "config.hpp"

screen::GameScreen::GameScreen()
{
    float width = 120;
    float height = 30;
    float x = WIDTH / 2 - width / 2;
    float y = WIDTH / 2 - height / 2;
    auto rect = (Rectangle){x, y, width, height};
    auto text = GuiIconText(ICON_PLAYER_PLAY, "Start Game");

    _startBtn = std::make_unique<widget::Button>(rect, text);
    _grid = std::make_unique<widget::XOGrid>(10);
}

void screen::GameScreen::draw()
{
    _grid->draw();
    _startBtn->draw();
}