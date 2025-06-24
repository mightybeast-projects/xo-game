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
        XOGrid(int size);

        void draw();

    private:
        std::unique_ptr<xo::XO> _xo;
        std::vector<std::vector<widget::Cell>> _cells;

        void initGame(int size);
        void initCell(int i, int j);
        void drawFrame();
        void drawSeparators();
        void drawCells();
        void drawRestartDialog();

        inline float cellSize()
        {
            return WIDTH / _xo->size();
        }
    };
}