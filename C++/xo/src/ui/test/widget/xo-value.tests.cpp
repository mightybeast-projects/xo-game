#include "mock-renderer.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "xo-value.hpp"
#include "types.hpp"

TEST(XOValueWidget, Should_Draw_Value_With_Specified_Position_Size_And_Color)
{
    const auto text = "x";
    const auto x = 1;
    const auto y = 2;
    const auto size = 10;
    const Col color = {255, 150, 69, 255};

    const widget::XOValue widget = widget::XOValue(text, x, y, size, color);

    const mock::MockRenderer renderer;

    EXPECT_CALL(renderer, drawText(text, x, y - size / 3.3, size, color)).Times(1);

    widget.draw(renderer);
}