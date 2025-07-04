#include "mock-renderer.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "x.hpp"
#include "types.hpp"

TEST(XWidget, Should_Draw_X_Value_With_Specified_Position_And_Size)
{
    const auto x = 1;
    const auto y = 2;
    const auto size = 10;
    const Col color = {99, 141, 219, 255};

    widget::X widget = widget::X(x, y, size);

    mock::MockRenderer renderer;

    EXPECT_CALL(renderer, drawText("x", x, y - size / 3.3, size, color)).Times(1);

    widget.draw(renderer);
}