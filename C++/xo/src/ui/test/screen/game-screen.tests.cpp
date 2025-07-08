#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "game-screen.hpp"
#include "mock-renderer.hpp"

TEST(GameScreen, Should_Draw_XO_Grid)
{
    using testing::_;

    const mock::MockRenderer renderer;
    screen::GameScreen screen;

    EXPECT_CALL(renderer, drawRectangleRounded(_, _, _, _)).Times(9);

    screen.draw(renderer);
}