#include "config.hpp"
#include "game-screen.hpp"
#include "screen-manager.hpp"
#include "main-menu-screen.hpp"
#include <iostream>
#include <memory>
#include "raylib-renderer.hpp"

int main()
{
    auto renderer = std::make_shared<gfx::RaylibRenderer>();
    auto screenManager = std::make_unique<screen::ScreenManager>();
    auto mainMenuScreen = std::make_unique<screen::MainMenuScreen>(renderer);

    screenManager->switchTo(std::move(mainMenuScreen));

    const auto onDraw = [&]()
    {
        screenManager->draw();
    };

    renderer->initGameWindow();
    renderer->draw(onDraw);
    renderer->closeGameWindow();
}