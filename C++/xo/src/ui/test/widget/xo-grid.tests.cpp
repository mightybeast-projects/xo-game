#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock-renderer.hpp"
#include "xo.hpp"
#include "xo-grid.hpp"
#include <memory>

using testing::_;

struct XOGridWidget : public testing::Test
{
    const mock::MockRenderer renderer;
    const std::unique_ptr<xo::XO> xo = std::make_unique<xo::XO>(3);

    widget::XOGrid widget = widget::XOGrid(xo.get());
};

TEST_F(XOGridWidget, Should_Draw_Empty_Cell_Grid)
{
    for (int i = 0; i < xo->size(); i++)
    {
        for (int j = 0; j < xo->size(); j++)
        {
            const float padding = 5;
            const float x = i * WIDTH / xo->size() + padding;
            const float y = j * WIDTH / xo->size() + padding;
            const float size = WIDTH / xo->size() - padding * 2;

            Rect rect = {x, y, size, size};

            EXPECT_CALL(renderer, drawRectangleRounded(rect, _, _, _));
        }
    }

    widget.draw(renderer);
}

TEST_F(XOGridWidget, Should_Draw_Cell_Grid_With_Set_Values)
{
    widget.clickTile(0, 0);
    widget.clickTile(0, 2);
    widget.clickTile(1, 1);

    EXPECT_CALL(renderer, drawText("x", _, _, _, _)).Times(2);
    EXPECT_CALL(renderer, drawText("o", _, _, _, _)).Times(1);

    widget.draw(renderer);
}

TEST_F(XOGridWidget, Should_Fire_On_Tile_Click_Event)
{
    bool clicked = false;

    auto onTileClick = [&]()
    {
        clicked = true;
    };

    widget.onAfterTileClick(onTileClick);

    widget.clickTile(0, 0);

    EXPECT_EQ(clicked, true);
}