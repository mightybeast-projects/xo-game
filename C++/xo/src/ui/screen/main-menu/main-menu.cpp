#include "main-menu.hpp"
#include "config.hpp"
#include "raygui.h"
#include "game-screen.hpp"
#include "x.hpp"
#include "o.hpp"

screen::MainMenuScreen::MainMenuScreen()
{
    drawLogo();
    drawStartButton();
}

void screen::MainMenuScreen::draw()
{
    Screen::draw();
}

void screen::MainMenuScreen::drawLogo()
{
    const float size = 75;

    const float padding = 20;

    const float xCenter = WIDTH / 2;
    const float yCenter = WIDTH / 2;

    const float xx = xCenter - size / 2;
    const float xy = yCenter - size * 1.25;
    const float ox = xCenter + 75 / 2 + padding / 2 - size / 2;
    const float oy = yCenter + 75 / 2 + padding / 2 - size * 1.25;

    _widgets.push_back(std::make_unique<widget::X>(xx, xy, size));
    _widgets.push_back(std::make_unique<widget::O>(ox, oy, size));
}

void screen::MainMenuScreen::drawStartButton()
{
    const float width = 120;
    const float height = 30;
    const float x = WIDTH / 2 - width / 2;
    const float y = WIDTH / 2 - height / 2 + 50;

    const auto rect = (Rectangle){x, y, width, height};
    const auto text = GuiIconText(ICON_PLAYER_PLAY, "Start Game");

    const auto cb = [this]()
    {
        _sm->switchTo(new screen::GameScreen());
    };

    _widgets.push_back(std::make_unique<widget::Button>(rect, text, cb));
}