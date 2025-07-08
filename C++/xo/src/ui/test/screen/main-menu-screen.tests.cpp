#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "main-menu-screen.hpp"
#include "mock-renderer.hpp"

TEST(MainMenuScreen, Should_Draw_Logo_And_Play_Button)
{
    using testing::_;

    const mock::MockRenderer renderer;
    screen::MainMenuScreen screen;

    EXPECT_CALL(renderer, drawRectangleRounded(_, _, _, _)).Times(4);
    EXPECT_CALL(renderer, drawText("x", _, _, _, _));
    EXPECT_CALL(renderer, drawText("o", _, _, _, _));

    EXPECT_CALL(renderer, drawGuiButton(_, _));

    screen.draw(renderer);
}