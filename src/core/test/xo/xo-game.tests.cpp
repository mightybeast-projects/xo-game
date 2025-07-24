#include "xo-game.fixture.hpp"

TEST_F(XOGame, Should_Have_Size_Specified_On_Initialization)
{
    EXPECT_EQ(xo.size(), 3);
}

TEST_F(XOGame, Should_Have_Empty_Cells_On_Initialization)
{
    for (auto i = 0; i < xo.size(); i++)
        for (auto j = 0; j < xo.size(); j++)
            EXPECT_EQ(xo.cells()[i][j], std::nullopt);
}

TEST_F(XOGame, Should_Place_Value)
{
    const auto res = xo.place(1, 2, xo::X);

    EXPECT_EQ(xo.cells()[1][2], xo::X);
    EXPECT_TRUE(res);
}

TEST_F(XOGame, Should_Not_Place_Value_On_Already_Occupied_Cell)
{
    xo.place(1, 2, xo::X);

    const auto res = xo.place(1, 2, xo::O);

    EXPECT_EQ(xo.cells()[1][2], xo::X);
    EXPECT_FALSE(res);
}

TEST_F(XOGame, Should_Not_Place_Value_If_Index_Is_Out_Of_Bounds)
{
    const auto res1 = xo.place(0, 3, xo::X);
    const auto res2 = xo.place(-1, 1, xo::X);

    for (auto i = 0; i < xo.size(); i++)
        for (auto j = 0; j < xo.size(); j++)
            EXPECT_EQ(xo.cells()[i][j], std::nullopt);

    EXPECT_FALSE(res1);
    EXPECT_FALSE(res2);
}

TEST_F(XOGame, Should_Not_Place_Value_If_It_Has_A_Winner)
{
    xo.place(0, 0, xo::X);
    xo.place(1, 1, xo::X);
    xo.place(2, 2, xo::X);

    const auto res = xo.place(0, 1, xo::X);

    EXPECT_EQ(xo.cells()[0][1], std::nullopt);
    EXPECT_FALSE(res);
}

TEST_F(XOGame, Should_Place_Next_Value_Starting_With_X)
{
    const auto res = xo.placeNext(0, 2);

    EXPECT_EQ(xo.cells()[0][2], xo::X);
    EXPECT_TRUE(res);
}

TEST_F(XOGame, Should_Switch_Value_After_Every_Next_Placement)
{
    const auto res1 = xo.placeNext(0, 1);
    const auto res2 = xo.placeNext(1, 1);
    const auto res3 = xo.placeNext(2, 2);

    EXPECT_EQ(xo.cells()[0][1], xo::X);
    EXPECT_EQ(xo.cells()[1][1], xo::O);
    EXPECT_EQ(xo.cells()[2][2], xo::X);
    EXPECT_TRUE(res1);
    EXPECT_TRUE(res2);
    EXPECT_TRUE(res3);
}