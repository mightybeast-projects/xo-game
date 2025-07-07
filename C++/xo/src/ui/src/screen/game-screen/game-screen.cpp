#include "game-screen.hpp"
#include "main-menu-screen.hpp"
#include "config.hpp"
#include "xo-grid.hpp"

screen::GameScreen::GameScreen()
{
    initGame();
}

void screen::GameScreen::draw(const gfx::Renderer &renderer)
{
    Screen::draw(renderer);

    if (_dialog != nullptr)
        _dialog->draw(renderer);
}

void screen::GameScreen::initGame()
{
    _xo = std::make_unique<xo::XO>(3);

    auto grid = std::make_unique<widget::XOGrid>(_xo.get());
    auto onTileClick = [this]()
    {
        if (_xo->isDraw() || _xo->winner().has_value())
            initRestartDialog();
    };

    grid->onTileClick(onTileClick);

    _widgets.push_back(std::move(grid));
}

void screen::GameScreen::initRestartDialog()
{
    _dialog = std::make_unique<widget::RestartDialog>(_xo.get());
    auto onRestart = [this]()
    {
        _dialog.reset();
        _widgets.clear();

        initGame();
    };
    auto onQuit = [this]()
    {
        _screenManager->switchTo(std::make_unique<screen::MainMenuScreen>());
    };

    _dialog->onRestart(onRestart);
    _dialog->onQuit(onQuit);
}