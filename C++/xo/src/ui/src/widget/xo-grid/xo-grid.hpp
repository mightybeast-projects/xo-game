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
        XOGrid(xo::XO *xo, gfx::Renderer *renderer);

        void draw() override;

    private:
        xo::XO *_xo;
        std::vector<std::vector<widget::Cell>> _cells;

        void initCell(int i, int j);
        void drawRestartDialog();

        inline float cellSize()
        {
            return WIDTH / _xo->size();
        }
    };
}