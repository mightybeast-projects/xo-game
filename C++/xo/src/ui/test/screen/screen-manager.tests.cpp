#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "mock-screen.hpp"
#include "mock-renderer.hpp"
#include <memory>

using testing::_;

struct ScreenManager : public testing::Test
{
    screen::ScreenManager screenManager;
};

TEST_F(ScreenManager, Should_Switch_Current_Screen)
{
    auto screen = std::make_unique<mock::MockScreen>();

    screenManager.switchTo(std::move(screen));
}

TEST_F(ScreenManager, Should_Draw_Current_Screen)
{
    const mock::MockRenderer renderer;

    auto screen = std::make_unique<mock::MockScreen>();

    screenManager.switchTo(std::move(screen));

    EXPECT_CALL(renderer, drawText("x", _, _, _, _)).Times(1);

    screenManager.draw(renderer);
}