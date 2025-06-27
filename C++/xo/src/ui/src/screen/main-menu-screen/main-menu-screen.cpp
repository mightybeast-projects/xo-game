#include "main-menu-screen.hpp"
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
    const auto size = 50;
    const auto offset = 75;
    const auto padding = 2.5;

    const float p[4][2] = {
        {WIDTH / 2 - size - padding, WIDTH / 2 - size - offset - padding},
        {WIDTH / 2 + padding, WIDTH / 2 - size - offset - padding},
        {WIDTH / 2 - size - padding, WIDTH / 2 - offset + padding},
        {WIDTH / 2 + padding, WIDTH / 2 - offset + padding},
    };

    _widgets.push_back(std::make_unique<widget::Cell>(p[0][0], p[0][1], size, xo::X, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(p[1][0], p[1][1], size, std::nullopt, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(p[2][0], p[2][1], size, std::nullopt, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(p[3][0], p[3][1], size, xo::O, nullptr));
}
 
void screen::MainMenuScreen::drawStartButton() 
{
    const float width = 100;
    const float height = 30;
    const float x = WIDTH / 2 - width / 2;
    const float y = WIDTH / 2 - height / 2 + 50;
    const Rectangle rect = {x, y, width, height};
    const auto text = GuiIconText(ICON_PLAYER_PLAY, "Play");

    const auto cb = [this]()
    {
        _screenManager->switchTo(std::make_unique<screen::GameScreen>());
    };

    _widgets.push_back(std::make_unique<widget::Button>(rect, text, cb));
}