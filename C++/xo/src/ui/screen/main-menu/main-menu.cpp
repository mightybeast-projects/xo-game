#include "main-menu.hpp"
#include "config.hpp"
#include "raygui.h"

screen::MainMenuScreen::MainMenuScreen()
{
    float width = 120;
    float height = 30;
    float x = WIDTH / 2 - width / 2;
    float y = WIDTH / 2 - height / 2;
    auto rect = (Rectangle){x, y, width, height};
    auto text = GuiIconText(ICON_PLAYER_PLAY, "Start Game");

    _startBtn = std::make_unique<widget::Button>(rect, text);
}

void screen::MainMenuScreen::draw()
{
    _startBtn->draw();
}
