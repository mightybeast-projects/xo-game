#pragma once

#include "xo.hpp"
#include <memory>

namespace widget
{
    struct XOGrid
    {
        XOGrid(int size);

        void draw();

    private:
        std::unique_ptr<xo::XO> _xo;
    };
}