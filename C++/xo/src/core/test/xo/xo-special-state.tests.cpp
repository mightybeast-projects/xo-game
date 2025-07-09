#include "xo-game.fixture.hpp"

TEST_F(XOGame, Should_Not_Be_In_Draw_State_If_Not_All_Cells_Are_Occupied)
{
    EXPECT_FALSE(xo.isInDrawState());
}

TEST_F(XOGame, Should_Not_Be_In_Draw_State_If_There_Is_A_Winner)
{
    xo.place(0, 0, xo::O);
    xo.place(0, 1, xo::O);

    xo.place(1, 0, xo::X);
    xo.place(1, 1, xo::X);
    xo.place(1, 2, xo::O);

    xo.place(2, 0, xo::X);
    xo.place(2, 1, xo::X);
    xo.place(2, 2, xo::O);

    xo.place(0, 2, xo::X);

    EXPECT_FALSE(xo.isInDrawState());
}

TEST_F(XOGame,
    Should_Be_In_Draw_State_If_All_Cells_Are_Occupied_And_There_Is_No_Winner)
{
    xo.place(0, 0, xo::O);
    xo.place(0, 1, xo::X);
    xo.place(0, 2, xo::O);

    xo.place(1, 0, xo::O);
    xo.place(1, 1, xo::X);
    xo.place(1, 2, xo::X);

    xo.place(2, 0, xo::X);
    xo.place(2, 1, xo::O);
    xo.place(2, 2, xo::X);

    EXPECT_EQ(xo.winner(), std::nullopt);
    EXPECT_TRUE(xo.isInDrawState());
}

TEST_F(XOGame, Should_Not_End_If_There_Is_No_Draw_Or_Winner)
{
    EXPECT_FALSE(xo.hasEnded());
}

TEST_F(XOGame, Should_End_If_There_Is_A_Draw)
{
    xo.place(0, 0, xo::O);
    xo.place(0, 1, xo::X);
    xo.place(0, 2, xo::O);

    xo.place(1, 0, xo::O);
    xo.place(1, 1, xo::X);
    xo.place(1, 2, xo::X);

    xo.place(2, 0, xo::X);
    xo.place(2, 1, xo::O);
    xo.place(2, 2, xo::X);

    EXPECT_TRUE(xo.hasEnded());
}

TEST_F(XOGame, Should_End_If_There_Is_A_Winner)
{
    xo.place(0, 0, xo::X);
    xo.place(1, 1, xo::X);
    xo.place(2, 2, xo::X);

    EXPECT_TRUE(xo.hasEnded());
}