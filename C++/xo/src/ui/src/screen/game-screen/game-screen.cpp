#include "game-screen.hpp"
#include "main-menu-screen.hpp"
#include "config.hpp"
#include "xo-grid.hpp"

screen::GameScreen::GameScreen()
{
    _xo = std::make_unique<xo::XO>(3);

    auto dialog = initRestartDialog();
    auto grid = initGrid(dialog.get());

    _widgets.push_back(std::move(grid));
    _widgets.push_back(std::move(dialog));
}

std::unique_ptr<widget::RestartDialog> screen::GameScreen::initRestartDialog()
{
    auto dialog = std::make_unique<widget::RestartDialog>(_xo.get());

    const auto onRestart = [this]()
    {
        _screenManager->switchTo(std::make_unique<screen::GameScreen>());
    };
    const auto onQuit = [this]()
    {
        _screenManager->switchTo(std::make_unique<screen::MainMenuScreen>());
    };

    dialog->onRestart(onRestart);
    dialog->onQuit(onQuit);

    return dialog;
}

std::unique_ptr<widget::XOGrid> screen::GameScreen::initGrid(widget::RestartDialog *dialog)
{
    auto grid = std::make_unique<widget::XOGrid>(_xo.get());

    const auto onAfterTileClick = [this, dialog]()
    {
        if (_xo->isDraw() || _xo->winner().has_value())
            dialog->show();
    };

    grid->onAfterTileClick(onAfterTileClick);

    return grid;
}