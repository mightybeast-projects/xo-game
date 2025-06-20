#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "config.hpp"

screen::GameScreen::GameScreen()
{
    auto grid = std::make_unique<widget::XOGrid>(10);

    _widgets.push_back(std::move(grid));
}