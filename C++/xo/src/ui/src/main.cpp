#include "config.hpp"
#include "game-screen.hpp"
#include "screen-manager.hpp"
#include "main-menu-screen.hpp"
#include <iostream>
#include <memory>
#include "raylib-renderer.hpp"

int main()
{
    const auto renderer = std::make_unique<gfx::RaylibRenderer>();
    const auto screenManager = std::make_unique<screen::ScreenManager>();

    auto mainMenuScreen = std::make_unique<screen::MainMenuScreen>();

    screenManager->switchTo(std::move(mainMenuScreen));

    const auto onDraw = [&]()
    {
        screenManager->draw(*renderer);
    };

    renderer->initGameWindow();
    renderer->draw(onDraw);
    renderer->closeGameWindow();
}