#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "main-menu-screen.hpp"
#include "mock-renderer.hpp"

using testing::_;

struct MainMenuScreen : public testing::Test
{
    screen::MainMenuScreen screen;
    mock::MockRenderer renderer;
};

TEST_F(MainMenuScreen, Should_Draw_Logo_And_Play_Button)
{
    EXPECT_CALL(renderer, drawRectangleRounded(_, _, _, _)).Times(4);
    EXPECT_CALL(renderer, drawText("x", _, _, _, _));
    EXPECT_CALL(renderer, drawText("o", _, _, _, _));

    EXPECT_CALL(renderer, drawGuiButton(_, _));

    screen.draw(renderer);
}