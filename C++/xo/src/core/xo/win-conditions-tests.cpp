#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;

struct XOWinConditions : public Test
{
    XO xo = XO(3);
};

TEST_F(XOWinConditions, Newly_Created_XO_Should_Not_Be_Finished)
{
    EXPECT_EQ(xo.finished(), false);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Diagonal_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(1, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Diagonal_Win_Condition_2)
{
    xo.place(0, 2, X);
    xo.place(1, 1, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Vertical_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(0, 1, X);
    xo.place(0, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Vertical_Win_Condition_2)
{
    xo.place(1, 0, X);
    xo.place(1, 1, X);
    xo.place(1, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Vertical_Win_Condition_3)
{
    xo.place(2, 0, X);
    xo.place(2, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Horizontal_Win_Condition_1)
{
    xo.place(0, 0, X);
    xo.place(1, 0, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Horizontal_Win_Condition_2)
{
    xo.place(0, 1, X);
    xo.place(1, 1, X);
    xo.place(2, 1, X);

    EXPECT_EQ(xo.finished(), true);
}

TEST_F(XOWinConditions, Should_Be_Finished_With_Horizontal_Win_Condition_3)
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