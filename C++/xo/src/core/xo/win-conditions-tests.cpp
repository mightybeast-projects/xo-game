#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;

struct XOWinConditions : public Test
{
    XO xo = XO(3);
};

TEST_F(XOWinConditions, Winner_In_Newly_Created_XO_Should_Not_Be_Defined)
{
    EXPECT_EQ(xo.getWinner(), std::nullopt);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Diagonal_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(1, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Diagonal_Win_Condition_2)
{
    xo.place(0, 2, X);
    xo.place(1, 1, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Vertical_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(0, 1, X);
    xo.place(0, 2, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Vertical_Win_Condition_2)
{
    xo.place(1, 0, X);
    xo.place(1, 1, X);
    xo.place(1, 2, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Vertical_Win_Condition_3)
{
    xo.place(2, 0, X);
    xo.place(2, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Horizontal_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(1, 0, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Horizontal_Win_Condition_2)
{
    xo.place(0, 1, X);
    xo.place(1, 1, X);
    xo.place(2, 1, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Have_Winner_With_Horizontal_Win_Condition_3)
{
    xo.place(0, 2, X);
    xo.place(1, 2, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.getWinner().has_value(), true);
}

TEST_F(XOWinConditions, Should_Get_Winner)
{
    xo.place(0, 2, O);
    xo.place(1, 2, O);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.getWinner(), O);
}