#include "mock-renderer.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "o.hpp"
#include "types.hpp"

TEST(OWidget, Should_Draw_O_Value_With_Specified_Position_And_Size)
{
    const auto x = 1;
    const auto y = 2;
    const auto size = 10;
    const Col color = {255, 150, 69, 255};

    widget::O widget = widget::O(x, y, size);

    mock::MockRenderer renderer;

    EXPECT_CALL(renderer, drawText("o", x, y - size / 3.3, size, color)).Times(1);

    widget.draw(renderer);
}