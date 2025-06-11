#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;
using namespace testing;

struct XO_Tests : public Test
{
    XO xo = XO(3);
};

TEST_F(XO_Tests, XO_Should_Have_Size_Specified_On_Initialization)
{
    EXPECT_EQ(xo.getSize(), 3);
}

TEST_F(XO_Tests, Newly_Created_XO_Should_Have_Empty_Cells)
{
    auto state = xo.state();

    for (auto i = 0; i < xo.getSize(); i++)
        for (auto j = 0; j < xo.getSize(); j++)
            EXPECT_EQ(state[i][j], EMPTY);
}

TEST_F(XO_Tests, XO_Should_Place_Value)
{
    xo.place(1, 2, X);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.state()[1][2], X);
    EXPECT_EQ(xo.state()[2][2], O);
}

TEST_F(XO_Tests, XO_Should_Not_Place_Empty_Value)
{
    xo.place(1, 2, X);
    xo.place(1, 2, EMPTY);

    EXPECT_EQ(xo.state()[1][2], X);
}