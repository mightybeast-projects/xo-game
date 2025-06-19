#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "config.hpp"

screen::GameScreen::GameScreen()
{
    _grid = std::make_unique<widget::XOGrid>(10);
}

void screen::GameScreen::draw()
{
    _grid->draw();
}