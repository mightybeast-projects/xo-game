#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "restart-dialog.hpp"
#include "mock-renderer.hpp"
#include "xo.hpp"

using testing::_;

struct RestartDialog : public testing::Test
{
    const mock::MockRenderer renderer;
    const std::string title = "#191#Game over!";
    const std::string btns = "Restart;Quit";
    const std::unique_ptr<xo::XO> xo = std::make_unique<xo::XO>(3);

    widget::RestartDialog widget = widget::RestartDialog(xo.get());
};

TEST_F(RestartDialog, Should_Not_Be_Drawn_By_Default)
{
    EXPECT_CALL(renderer, drawGuiMessageBox(_, _, _, _)).Times(0);

    widget.draw(renderer);
}

TEST_F(RestartDialog, Should_Draw_Message_Box_With_Draw_Message_If_XO_Game_Has_Ended_In_Draw)
{
    xo->place(0, 0, xo::O);
    xo->place(0, 1, xo::X);
    xo->place(0, 2, xo::O);

    xo->place(1, 0, xo::O);
    xo->place(1, 1, xo::X);
    xo->place(1, 2, xo::X);

    xo->place(2, 0, xo::X);
    xo->place(2, 1, xo::O);
    xo->place(2, 2, xo::X);

    const auto message = "Draw!";

    EXPECT_CALL(renderer, drawGuiMessageBox(_, title, message, btns)).Times(1);

    widget.draw(renderer);
}

TEST_F(RestartDialog, Should_Draw_Message_Box_With_X_Player_Won_Message_If_X_Player_Won)
{
    xo->place(0, 0, xo::X);
    xo->place(1, 1, xo::X);
    xo->place(2, 2, xo::X);

    const auto message = "X player won!";

    EXPECT_CALL(renderer, drawGuiMessageBox(_, title, message, btns)).Times(1);

    widget.draw(renderer);
}

TEST_F(RestartDialog, Should_Draw_Message_Box_With_O_Player_Won_Message_If_O_Player_Won)
{
    xo->place(0, 0, xo::O);
    xo->place(1, 1, xo::O);
    xo->place(2, 2, xo::O);

    const auto message = "O player won!";

    EXPECT_CALL(renderer, drawGuiMessageBox(_, title, message, btns)).Times(1);

    widget.draw(renderer);
}

TEST_F(RestartDialog, Should_Fire_Restart_Event_On_Restart_Button_Click)
{
    xo->place(0, 0, xo::X);
    xo->place(1, 1, xo::X);
    xo->place(2, 2, xo::X);

    bool restarted = false;

    const auto onRestart = [&]()
    {
        restarted = true;
    };

    widget.onRestart(onRestart);

    EXPECT_CALL(renderer, drawGuiMessageBox).WillOnce(::testing::Return(1));

    widget.draw(renderer);

    EXPECT_TRUE(restarted);
}

TEST_F(RestartDialog, Should_Fire_Quit_Event_On_Quit_Button_Click)
{
    xo->place(0, 0, xo::X);
    xo->place(1, 1, xo::X);
    xo->place(2, 2, xo::X);

    bool quit = false;

    const auto onQuit = [&]()
    {
        quit = true;
    };

    widget.onQuit(onQuit);

    EXPECT_CALL(renderer, drawGuiMessageBox).WillOnce(::testing::Return(2));

    widget.draw(renderer);

    EXPECT_TRUE(quit);
}