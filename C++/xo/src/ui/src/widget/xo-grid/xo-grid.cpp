#include "xo-grid.hpp"
#include "xo.hpp"
#include "config.hpp"
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
    const float padding = 5;
    const float x = cellSize() * i + padding;
    const float y = cellSize() * j + padding;
    const float size = cellSize() - padding * 2;
    const Rect rect = {x, y, size, size};

    const auto placeNextValue = [this, i, j]()
    {
        auto res = _xo->placeNext(i, j);

        if (res)
            _cells[i][j].setValue(_xo->cells()[i][j].value());
    };

    auto cell = widget::Cell(rect);

    cell.onClick(placeNextValue);

    _cells[i].push_back(std::move(cell));
}
