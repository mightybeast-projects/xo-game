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
            EXPECT_EQ(state[i][j], XOValue::EMPTY);
}