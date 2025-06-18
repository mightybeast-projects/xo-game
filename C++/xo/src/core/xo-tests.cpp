#include <gtest/gtest.h>
#include "xo.hpp"

struct XOGame : public testing::Test
{
    xo::XO xo = xo::XO(3);
};

TEST_F(XOGame, Should_Have_Size_Specified_On_Initialization)
{
    EXPECT_EQ(xo.size(), 3);
}

TEST_F(XOGame, Should_Have_Empty_Cells_On_Initialization)
{
    for (auto i = 0; i < xo.size(); i++)
        for (auto j = 0; j < xo.size(); j++)
            EXPECT_EQ(xo.state()[i][j], std::nullopt);
}

TEST_F(XOGame, Should_Place_Value)
{
    xo.place(1, 2, xo::X);
    xo.place(2, 2, xo::O);

    EXPECT_EQ(xo.state()[1][2], xo::X);
    EXPECT_EQ(xo.state()[2][2], xo::O);
}

TEST_F(XOGame, Should_Not_Place_Value_On_Already_Occupied_Cell)
{
    xo.place(1, 2, xo::X);
    xo.place(1, 2, xo::O);

    EXPECT_EQ(xo.state()[1][2], xo::X);
}

TEST_F(XOGame, Should_Not_Place_Value_If_Index_Is_Out_Of_Bounds)
{
    xo.place(0, 3, xo::X);
    xo.place(-1, 1, xo::X);

    for (auto i = 0; i < xo.size(); i++)
        for (auto j = 0; j < xo.size(); j++)
            EXPECT_EQ(xo.state()[i][j], std::nullopt);
}

TEST_F(XOGame, Should_Not_Place_Value_If_It_Has_A_Winner)
{
    xo.place(0, 0, xo::X);
    xo.place(1, 1, xo::X);
    xo.place(2, 2, xo::X);

    xo.place(0, 1, xo::X);

    EXPECT_EQ(xo.state()[0][1], std::nullopt);
}

TEST_F(XOGame, Should_Place_Next_Value_Starting_With_X)
{
    xo.placeNext(0, 2);

    EXPECT_EQ(xo.state()[0][2], xo::X);
}

TEST_F(XOGame, Should_Switch_Value_After_Every_Next_Placement)
{
    xo.placeNext(0, 1);
    xo.placeNext(1, 1);
    xo.placeNext(2, 2);

    EXPECT_EQ(xo.state()[0][1], xo::X);
    EXPECT_EQ(xo.state()[1][1], xo::O);
    EXPECT_EQ(xo.state()[2][2], xo::X);
}