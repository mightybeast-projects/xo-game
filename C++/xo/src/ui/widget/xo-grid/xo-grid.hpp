#pragma once

#include "xo.hpp"
#include <memory>
#include "drawable.hpp"
#include "config.hpp"

namespace widget
{
    struct XOGrid : common::Drawable
    {
        XOGrid(int size);

        void draw();

    private:
        std::unique_ptr<xo::XO> _xo;

        void drawFrame();
        void drawSeparators();
        void drawCells();

        inline float cellSize()
        {
            return WIDTH / _xo->size();
        }
    };
}