#include "game-screen.hpp"
#include "main-menu-screen.hpp"
#include "config.hpp"
#include "xo-grid.hpp"

screen::GameScreen::GameScreen()
{
    _xo = std::make_unique<xo::XO>(3);

    _widgets.push_back(std::make_unique<widget::XOGrid>(_xo.get()));

    initRestartDialog();
}

void screen::GameScreen::initRestartDialog()
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

    _widgets.push_back(std::move(dialog));
}