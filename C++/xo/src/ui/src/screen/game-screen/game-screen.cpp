#include "raylib.h"
#include "raygui.h"
#include "game-screen.hpp"
#include "main-menu-screen.hpp"
#include "config.hpp"
#include "xo-grid.hpp"

screen::GameScreen::GameScreen()
{
    initGame();
}

void screen::GameScreen::draw()
{
    Screen::draw();

    if (_xo->isDraw() || _xo->winner().has_value())
        drawRestartDialog();
}

void screen::GameScreen::drawRestartDialog()
{
    std::string message;

    if (_xo->winner().has_value() && _xo->winner() == xo::X)
        message = "X player won!";
    if (_xo->winner().has_value() && _xo->winner() == xo::O)
        message = "O player won!";
    if (_xo->isDraw())
        message = "Draw!";

    const Rectangle r = {85, 70, 250, 100};
    const char *title = "#191#Game over!";
    const char *btnLables = "Restart;Quit";

    const auto box = GuiMessageBox(r, title, message.c_str(), btnLables);

    if (box == 1)
        initGame();
    if (box == 2)
        _screenManager->switchTo(std::make_unique<screen::MainMenuScreen>());
}

void screen::GameScreen::initGame()
{
    _xo = std::make_shared<xo::XO>(GAME_GRID_SIZE);

    _widgets.clear();
    _widgets.push_back(std::make_unique<widget::XOGrid>(_xo));
}