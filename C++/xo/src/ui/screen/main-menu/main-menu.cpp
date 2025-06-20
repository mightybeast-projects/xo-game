#include "main-menu.hpp"
#include "config.hpp"
#include "raygui.h"
#include "game-screen.hpp"
#include "x.hpp"
#include "o.hpp"

screen::MainMenuScreen::MainMenuScreen()
{
    initLogo();
    initStartButton();
}

void screen::MainMenuScreen::initLogo()
{
    float size = 50;

    float xx = WIDTH / 2 - size / 2 - size;
    float xy = WIDTH / 2 - size - 50;
    float ox = WIDTH / 2 + size / 2 + size / 3;
    float oy = WIDTH / 2 - size - 50 / 2;

    auto x = std::make_unique<widget::X>(xx, xy, size);
    auto o = std::make_unique<widget::O>(ox, oy, size);

    _widgets.push_back(std::move(x));
    _widgets.push_back(std::move(o));
}

void screen::MainMenuScreen::initStartButton()
{
    float width = 120;
    float height = 30;
    float x = WIDTH / 2 - width / 2;
    float y = WIDTH / 2 - height / 2 + 100;
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

void screen::MainMenuScreen::draw()
{
    Screen::draw();

    float x = WIDTH / 2;
    float y = WIDTH / 2 - 25;

    auto text = "(TicTacToe)";
    auto fontSize = 20;
    auto width = MeasureText(text, fontSize);

    DrawText(text, x - width / 2, y, fontSize, CROSS);
}