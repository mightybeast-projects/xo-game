#include <gtest/gtest.h>
#include "xo.hpp"

using namespace xo;

TEST(XO, XO_Should_Have_Size_Specified_On_Initialization)
{
    int size = 3;
    XO xo(size);

    EXPECT_EQ(xo.getSize(), size);
}

TEST(XO, Newly_Created_XO_Should_Have_Empty_Cells)
{
    XO xo(3);
    auto state = xo.state();

    for (auto i = 0; i < xo.getSize(); i++)
        for (auto j = 0; j < xo.getSize(); j++)
            EXPECT_EQ(state[i][j], EMPTY);
}

TEST(XO, XO_Should_Place_Value)
{
    XO xo(3);

    xo.place(1, 2, X);
    xo.place(2, 2, O);

    EXPECT_EQ(xo.state()[1][2], X);
    EXPECT_EQ(xo.state()[2][2], O);
}

TEST(XO, XO_Should_Not_Place_Empty_Value)
{
    XO xo(3);

    xo.place(1, 2, X);
    xo.place(1, 2, EMPTY);

    EXPECT_EQ(xo.state()[1][2], X);
}