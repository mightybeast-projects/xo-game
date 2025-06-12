#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;

struct XOWinConditions : public Test
{
    XO xo = XO(3);
};

TEST_F(XOWinConditions, Should_Check_Win_And_Return_False_On_Newly_Created_OX)
{
    EXPECT_EQ(xo.finished(), false);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Diagonal_Line_1)
{
    xo.place(0, 0, X);
    xo.place(1, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Diagonal_Line_2)
{
    xo.place(0, 2, X);
    xo.place(1, 1, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Vertical_Line_1)
{
    xo.place(0, 0, X);
    xo.place(0, 1, X);
    xo.place(0, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Vertical_Line_2)
{
    xo.place(1, 0, X);
    xo.place(1, 1, X);
    xo.place(1, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Vertical_Line_3)
{
    xo.place(2, 0, X);
    xo.place(2, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Horizontal_Line_1)
{
    xo.place(0, 0, X);
    xo.place(1, 0, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Horizontal_Line_2)
{
    xo.place(0, 1, X);
    xo.place(1, 1, X);
    xo.place(2, 1, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Check_Win_And_Return_True_If_Player_Won_With_Horizontal_Line_3)
{
    xo.place(0, 2, X);
    xo.place(1, 2, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Get_Winner)
{
    xo.place(0, 2, O);
    xo.place(1, 2, O);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.getWinner(), O);
}