#pragma once

#include "xo.hpp"

namespace widget
{
    struct XOGrid
    {
        XOGrid(int size);

        void draw();

    private:
        xo::XO *_xo;
    };
}