#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "config.hpp"
#include "game-screen.hpp"
#include "screen-manager.hpp"
#include "main-menu-screen.hpp"
#include <iostream>
#include <memory>
#include "raylib-renderer.hpp"

int main()
{
    auto renderer = std::make_unique<gfx::RaylibRenderer>();
    auto sm = std::make_unique<screen::ScreenManager>();

    sm->switchTo(std::make_unique<screen::MainMenuScreen>());

    const auto onDraw = [&]()
    {
        sm->draw();
    };

    renderer->initGameWindow();
    renderer->draw(onDraw);
    renderer->closeGameWindow();
}