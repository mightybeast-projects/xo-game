#include "xo-grid.hpp"
#include "xo.hpp"
#include "raygui.h"
#include "config.hpp"
#include "x.hpp"
#include "cell.hpp"
#include <optional>
#include <string>
#include "types.hpp"
#include "raylib-renderer.hpp"

widget::XOGrid::XOGrid(xo::XO *xo)
{
    _xo = xo;

    _cells.resize(_xo->size());

    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            initCell(i, j);
}

void widget::XOGrid::draw(const gfx::Renderer &renderer)
{
    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            _cells[i][j].draw(renderer);
}

void widget::XOGrid::initCell(int i, int j)
{
    auto padding = 5;
    auto x = cellSize() * i + padding;
    auto y = cellSize() * j + padding;
    auto size = cellSize() - padding * 2;
    auto value = _xo->cells()[i][j];

    auto cb = [this, i, j]()
    {
        auto res = _xo->placeNext(i, j);

        if (res)
            _cells[i][j].setValue(_xo->cells()[i][j].value());
    };

    _cells[i].push_back(widget::Cell({x, y, size, size}, value, cb));
}
