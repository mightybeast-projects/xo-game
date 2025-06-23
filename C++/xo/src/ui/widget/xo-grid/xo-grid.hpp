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

        void initCells();
        void drawFrame();
        void drawSeparators();
        void drawCells();

        inline float cellSize()
        {
            return WIDTH / _xo->size();
        }
    };
}