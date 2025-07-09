#include "config.hpp"
#include "game-screen.hpp"
#include "main-menu-screen.hpp"
#include "raylib-renderer.hpp"
#include "screen-manager.hpp"
#include <iostream>
#include <memory>

int main()
{
    const auto renderer = std::make_unique<gfx::RaylibRenderer>();
    const auto screenManager = std::make_unique<screen::ScreenManager>();

    auto mainMenuScreen = std::make_unique<screen::MainMenuScreen>();

    screenManager->switchTo(std::move(mainMenuScreen));

    renderer->initGameWindow();
    renderer->draw([&]() { screenManager->draw(*renderer); });
    renderer->closeGameWindow();
}