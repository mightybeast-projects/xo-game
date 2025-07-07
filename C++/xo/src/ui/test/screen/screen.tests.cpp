#include "mock-screen.hpp"
#include "mock-renderer.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

using testing::_;

struct Screen : public testing::Test
{
    mock::MockScreen screen;
    mock::MockRenderer renderer;
};

TEST_F(Screen, Should_Set_Its_Screen_Manager)
{
    const auto screenManager = std::make_unique<screen::ScreenManager>();

    screen.setScreenManager(screenManager.get());

    EXPECT_EQ(screen.screenManager(), screenManager.get());
}

TEST_F(Screen, Should_Draw_Its_Widgets)
{
    EXPECT_CALL(renderer, drawText(_, _, _, _, _)).Times(1);

    screen.draw(renderer);
}