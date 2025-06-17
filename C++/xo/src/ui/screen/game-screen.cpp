#include "raylib.h"
#include "game-screen.hpp"
#include "button.hpp"
#include "config.hpp"

using namespace screen;
using namespace widget;

void GameScreen::init()
{
    float btnWidth = 120;
    float btnHeight = 30;

    btn = Button((Rectangle){
                     WIDTH / 2 - btnWidth / 2,
                     HEIGHT / 2 - btnHeight / 2,
                     btnWidth,
                     btnHeight},
                 "#191#Start Game");

    x = X(100, 100, 50);
    o = O(50, 50, 25);
}

void GameScreen::draw()
{
    x.draw();
    o.draw();

    btn.draw();
}