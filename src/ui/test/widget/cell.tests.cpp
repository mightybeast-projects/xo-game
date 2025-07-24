#include "cell.hpp"
#include "mock-renderer.hpp"
#include "types.hpp"
#include "xo.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::_;

struct CellWidget : public testing::Test
{
    const mock::MockRenderer renderer;
    const Rect rect = { 0, 0, 100, 100 };
    const Col col = { 56, 56, 56, 255 };
    const float rs = 0.1;
    const int segs = 0;
};

TEST_F(CellWidget, Should_Draw_Cell_With_No_Value_If_It_Is_Not_Specified)
{
    widget::Cell widget = widget::Cell(rect);

    EXPECT_CALL(renderer, drawRectangleRounded(rect, rs, segs, col)).Times(1);
    EXPECT_CALL(renderer, drawText(_, _, _, _, _)).Times(0);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(CellWidget, Should_Draw_Cell_With_Specified_Position_Size_And_X_Value)
{
    widget::Cell widget = widget::Cell(rect, xo::X);

    EXPECT_CALL(renderer, drawRectangleRounded(rect, rs, segs, col)).Times(1);
    EXPECT_CALL(renderer, drawText("x", _, _, _, _)).Times(1);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(CellWidget, Should_Draw_Cell_With_Specified_Position_Size_And_O_Value)
{
    widget::Cell widget = widget::Cell(rect, xo::O);

    EXPECT_CALL(renderer, drawRectangleRounded(rect, rs, segs, col)).Times(1);
    EXPECT_CALL(renderer, drawText("o", _, _, _, _)).Times(1);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(CellWidget, Should_Set_Value)
{
    widget::Cell widget = widget::Cell(rect);

    widget.setValue(xo::X);

    EXPECT_CALL(renderer, drawRectangleRounded(rect, rs, segs, col)).Times(1);
    EXPECT_CALL(renderer, drawText("x", _, _, _, _)).Times(1);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(CellWidget, Should_Fire_Click_Event_On_Click)
{
    widget::Cell widget = widget::Cell(rect, xo::X);

    bool clicked = false;

    widget.onClick([&]() { clicked = true; });

    EXPECT_CALL(renderer, handleLeftClick(_, _))
        .WillOnce(testing::Invoke(
            [](const Rect&, const std::function<void()>& callback) {
                callback();
            }));

    widget.draw(renderer);

    EXPECT_TRUE(clicked);
}