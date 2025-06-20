#include "main-menu.hpp"
#include "config.hpp"
#include "raygui.h"
#include "game-screen.hpp"

screen::MainMenuScreen::MainMenuScreen()
{
    float width = 120;
    float height = 30;
    float x = WIDTH / 2 - width / 2;
    float y = WIDTH / 2 - height / 2;
    auto rect = (Rectangle){x, y, width, height};
    auto text = GuiIconText(ICON_PLAYER_PLAY, "Start Game");

    auto startBtn = std::make_unique<widget::Button>(rect, text);

    auto cb = [this]()
    {
        _sm->switchTo(new screen::GameScreen());
    };

    startBtn->onClick(cb);

    _widgets.push_back(std::move(startBtn));
}
