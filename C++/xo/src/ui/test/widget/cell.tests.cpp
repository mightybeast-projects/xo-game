#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "types.hpp"
#include "xo.hpp"
#include "cell.hpp"
#include "mock-renderer.hpp"

using testing::_;

struct CellWidget : public testing::Test
{
    const mock::MockRenderer renderer;
    const Rect rect = {0, 0, 0, 0};
    const Col color = {56, 56, 56, 255};
    const std::function<void()> onClick = []() {};

    widget::Cell widget = widget::Cell(rect, std::nullopt, onClick);
};

TEST_F(CellWidget, Should_Draw_Cell_With_No_Value_If_It_Is_Not_Specified)
{
    EXPECT_CALL(renderer, drawRectangleRounded(rect, 0.1, 0, color)).Times(1);
    EXPECT_CALL(renderer, drawText(_, _, _, _, _)).Times(0);
    EXPECT_CALL(renderer, handleLeftClick(rect, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(CellWidget, Should_Draw_Cell_With_Specified_Position_Size_And_Value)
{
}

TEST_F(CellWidget, Should_Set_Value)
{
}

TEST_F(CellWidget, Should_Fire_Click_Event_On_Click)
{
}