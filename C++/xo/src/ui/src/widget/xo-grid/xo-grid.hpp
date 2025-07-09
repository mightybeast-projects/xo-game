#pragma once

#include "cell.hpp"
#include "config.hpp"
#include "drawable.hpp"
#include "xo.hpp"
#include <memory>
#include <vector>

namespace widget
{
    struct XOGrid : common::Drawable
    {
        XOGrid(xo::XO* xo);

        void draw(const gfx::Renderer& renderer) const override;

        inline void clickTile(int i, int j)
        {
            _cells[i][j]->click();
        }

    private:
        xo::XO* const _xo;

        std::vector<std::vector<std::unique_ptr<widget::Cell>>> _cells;
        std::function<void()> _onAfterTileClick;

        void initCell(int i, int j);

        inline float cellSize() const
        {
            return WIDTH / _xo->size();
        }
    };
}