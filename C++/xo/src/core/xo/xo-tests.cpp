#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;

struct XO_Tests : public Test
{
    XO xo = XO(3);
};

TEST_F(XO_Tests, Should_Have_Size_Specified_On_Initialization)
{
    EXPECT_EQ(xo.getSize(), 3);
}

TEST_F(XO_Tests, Newly_Created_XO_Should_Have_Empty_Cells)
{
    for (auto i = 0; i < xo.getSize(); i++)
        for (auto j = 0; j < xo.getSize(); j++)
            EXPECT_EQ(xo.state()[i][j], EMPTY);
}

TEST_F(XO_Tests, Should_Place_Value)
{
    xo.place(1, 2, X);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.state()[1][2], X);
    EXPECT_EQ(xo.state()[2][2], O);
}

TEST_F(XO_Tests, Should_Not_Place_Empty_Value)
{
    xo.place(1, 2, X);
    xo.place(1, 2, EMPTY);

    EXPECT_EQ(xo.state()[1][2], X);
}

TEST_F(XO_Tests, Should_Not_Place_Value_On_Already_Occupied_Cell)
{
    xo.place(1, 2, X);
    xo.place(1, 2, O);

    EXPECT_EQ(xo.state()[1][2], X);
}

TEST_F(XO_Tests, Should_Not_Place_Value_If_Index_Is_Out_Of_Bounds)
{
    xo.place(0, 3, X);
    xo.place(-1, 1, X);

    for (auto i = 0; i < xo.getSize(); i++)
        for (auto j = 0; j < xo.getSize(); j++)
            EXPECT_EQ(xo.state()[i][j], EMPTY);
}

TEST_F(XO_Tests, Should_Place_Next_Value_Starting_With_X)
{
    xo.placeNext(0, 2);

    EXPECT_EQ(xo.state()[0][2], X);
}

TEST_F(XO_Tests, Should_Switch_Next_Value_After_Every_Next_Placement)
{
    xo.placeNext(0, 1);
    xo.placeNext(1, 1);
    xo.placeNext(2, 2);

    EXPECT_EQ(xo.state()[0][1], X);
    EXPECT_EQ(xo.state()[1][1], O);
    EXPECT_EQ(xo.state()[2][2], X);
}

//---

TEST_F(XO_Tests, Should_Check_Win_And_Return_False_On_Newly_Created_OX)
{
    EXPECT_EQ(xo.checkWin(), false);
}

TEST_F(XO_Tests, Should_Check_Win_And_Return_True_If_Player_Won_With_Diagonal_Line_1)
{
    xo.place(0, 0, X);
    xo.place(1, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.checkWin(), true);
}

TEST_F(XO_Tests, Should_Check_Win_And_Return_True_If_Player_Won_With_Diagonal_Line_2)
{
    xo.place(0, 2, X);
    xo.place(1, 1, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.checkWin(), true);
}