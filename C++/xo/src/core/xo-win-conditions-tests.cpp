#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;
using namespace std;

struct XOGame : public Test
{
    XO xo = XO(3);
};

TEST_F(XOGame, Winner_Should_Not_Be_Defined_On_Initialization)
{
    EXPECT_EQ(xo.winner(), nullopt);
}

TEST_F(XOGame, Should_Have_Winner_If_Winning_Condition_Is_Met)
{
    xo.place(0, 2, O);
    xo.place(1, 2, O);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.winner(), O);
}

TEST_F(XOGame, Should_Have_Winner_When_Diagonal_Win_Condition_Is_Met_1)
{
    xo.place(0, 0, X);
    xo.place(1, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Diagonal_Win_Condition_Is_Met_2)
{
    xo.place(0, 2, X);
    xo.place(1, 1, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Vertical_Win_Condition_Is_Met_1)
{
    xo.place(0, 0, X);
    xo.place(0, 1, X);
    xo.place(0, 2, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Vertical_Win_Condition_Is_Met_2)
{
    xo.place(1, 0, X);
    xo.place(1, 1, X);
    xo.place(1, 2, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Vertical_Win_Condition_Is_Met_3)
{
    xo.place(2, 0, X);
    xo.place(2, 1, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Horizontal_Win_Condition_Is_Met_1)
{
    xo.place(0, 0, X);
    xo.place(1, 0, X);
    xo.place(2, 0, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Horizontal_Win_Condition_Is_Met_2)
{
    xo.place(0, 1, X);
    xo.place(1, 1, X);
    xo.place(2, 1, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}

TEST_F(XOGame, Should_Have_Winner_When_Horizontal_Win_Condition_Is_Met_3)
{
    xo.place(0, 2, X);
    xo.place(1, 2, X);
    xo.place(2, 2, X);

    EXPECT_EQ(xo.winner().has_value(), true);
}