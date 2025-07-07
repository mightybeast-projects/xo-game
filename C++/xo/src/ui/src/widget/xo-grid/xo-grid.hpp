#pragma once

#include "xo.hpp"
#include <memory>
#include <vector>
#include "drawable.hpp"
#include "config.hpp"
#include "cell.hpp"

namespace widget
{
    struct XOGrid : common::Drawable
    {
        XOGrid(xo::XO *xo);

        void draw(const gfx::Renderer &renderer) override;

        inline void clickTile(int i, int j)
        {
            _cells[i][j].click();
        }

    private:
        std::vector<std::vector<widget::Cell>> _cells;
        std::function<void()> _onAfterTileClick;
        xo::XO *_xo;

        void initCell(int i, int j);

        inline float cellSize()
        {
            return WIDTH / _xo->size();
        }
    };
}