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

    float x = WIDTH / 2;
    float y = WIDTH / 2 - 20;

    auto text = "also known as TicTacToe";
    auto fontSize = 5;
    auto width = MeasureText(text, fontSize);

    DrawText(text, x - width / 2, y, fontSize, CROSS);
}

void screen::MainMenuScreen::drawLogo()
{
    float size = 75;

    float padding = 20;

    float xCenter = WIDTH / 2;
    float yCenter = WIDTH / 2;

    float xx = xCenter - size / 2;
    float xy = yCenter - size * 1.75;
    float ox = xCenter + 75 / 2 + padding / 2 - size / 2;
    float oy = yCenter + 75 / 2 + padding / 2 - size * 1.75;

    auto x = std::make_unique<widget::X>(xx, xy, size);
    auto o = std::make_unique<widget::O>(ox, oy, size);

    _widgets.push_back(std::move(x));
    _widgets.push_back(std::move(o));
}

void screen::MainMenuScreen::drawStartButton()
{
    float width = 120;
    float height = 30;
    float x = WIDTH / 2 - width / 2;
    float y = WIDTH / 2 - height / 2 + 75;
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