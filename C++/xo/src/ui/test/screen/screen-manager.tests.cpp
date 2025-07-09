#include "mock-renderer.hpp"
#include "mock-screen.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

using testing::_;

struct ScreenManager : public testing::Test
{
    screen::ScreenManager screenManager;
    std::unique_ptr<mock::MockScreen> screen
        = std::make_unique<mock::MockScreen>();
    mock::MockScreen* screenPtr = screen.get();
};

TEST_F(ScreenManager, Should_Switch_Current_Screen)
{
    EXPECT_CALL(*screenPtr, setScreenManager(&screenManager));

    screenManager.switchTo(std::move(screen));
}

TEST_F(ScreenManager, Should_Draw_Current_Screen)
{
    const mock::MockRenderer renderer;

    screenManager.switchTo(std::move(screen));

    EXPECT_CALL(*screenPtr, draw(::testing::Ref(renderer))).Times(1);
    screenManager.draw(renderer);
}
