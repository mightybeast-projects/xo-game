#pragma once

#include "xo.hpp"
#include <memory>
#include "drawable.hpp"

namespace widget
{
    struct XOGrid : utils::Drawable
    {
        XOGrid(int size);

        void draw();

    private:
        std::unique_ptr<xo::XO> _xo;
    };
}