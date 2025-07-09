#include "button.hpp"
#include "mock-renderer.hpp"
#include <functional>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

using testing::_;

struct ButtonWidget : public testing::Test
{
    const mock::MockRenderer renderer;
    const Rect rect = { 0, 0, 100, 100 };
    const std::string text = "text";

    widget::Button widget = widget::Button(rect, text, nullptr);
};

TEST_F(ButtonWidget, Should_Draw_On_Position_With_Specified_Text)
{
    EXPECT_CALL(renderer, drawGuiButton(rect, text)).Times(1);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(ButtonWidget, Should_Fire_Click_Event_On_Click)
{
    bool clicked = false;

    widget.onClick([&]() { clicked = true; });

    auto cb = [](const Rect&, const std::function<void()>& callback) {
        callback();
    };

    EXPECT_CALL(renderer, handleLeftClick(_, _)).WillOnce(testing::Invoke(cb));

    widget.draw(renderer);

    EXPECT_TRUE(clicked);
}