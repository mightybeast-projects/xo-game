#include "main-menu-screen.hpp"
#include "config.hpp"
#include "raygui.h"
#include "game-screen.hpp"
#include "x.hpp"
#include "o.hpp"
#include "renderer.hpp"

screen::MainMenuScreen::MainMenuScreen(std::shared_ptr<gfx::Renderer> renderer)
    : Screen::Screen(renderer)
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

    const Rect rectangles[4] = {
        {WIDTH / 2 - size - padding, WIDTH / 2 - size - offset - padding, size, size},
        {WIDTH / 2 + padding, WIDTH / 2 - size - offset - padding, size, size},
        {WIDTH / 2 - size - padding, WIDTH / 2 - offset + padding, size, size},
        {WIDTH / 2 + padding, WIDTH / 2 - offset + padding, size, size},
    };

    _widgets.push_back(std::make_unique<widget::Cell>(rectangles[0], xo::X, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(rectangles[1], std::nullopt, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(rectangles[2], std::nullopt, nullptr));
    _widgets.push_back(std::make_unique<widget::Cell>(rectangles[3], xo::O, nullptr));
}

void screen::MainMenuScreen::drawStartButton()
{
    const float width = 100;
    const float height = 30;
    const float x = WIDTH / 2 - width / 2;
    const float y = WIDTH / 2 - height / 2 + 50;
    const Rect rect = {x, y, width, height};
    const auto text = GuiIconText(ICON_PLAYER_PLAY, "Play");

    const auto cb = [this]()
    {
        _screenManager->switchTo(std::make_unique<screen::GameScreen>(_renderer));
    };

    _widgets.push_back(std::make_unique<widget::Button>(rect, text, cb));
}