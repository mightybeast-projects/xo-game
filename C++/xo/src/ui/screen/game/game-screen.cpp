#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "config.hpp"

screen::GameScreen::GameScreen()
{
    _widgets.push_back(std::make_unique<widget::XOGrid>(GAME_GRID_SIZE));
}