#include "xo-grid.hpp"
#include "xo.hpp"
#include "config.hpp"
#include "x.hpp"
#include "cell.hpp"
#include <optional>

widget::XOGrid::XOGrid(int size)
{
    _xo = std::make_unique<xo::XO>(size);

    initCells();
}

void widget::XOGrid::draw()
{
    drawFrame();
    drawSeparators();
    drawCells();
}

void widget::XOGrid::initCells()
{
    auto col = std::vector<widget::Cell>(_xo->size());
    _cells = std::vector<std::vector<widget::Cell>>(_xo->size(), col);

    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            initCell(i, j);
}

void widget::XOGrid::initCell(int i, int j)
{
    auto padding = 4;
    auto x = cellSize() * i + padding;
    auto y = cellSize() * j + padding;
    auto size = cellSize() - padding * 2;
    auto value = _xo->state()[i][j];

    auto cell = widget::Cell(x, y, size, value);
    auto cb = [this, i, j]()
    {
        auto res = _xo->placeNext(i, j);

        if (res)
            _cells[i][j].setValue(_xo->state()[i][j].value());
    };

    cell.onClick(cb);

    _cells[i][j] = cell;
}

void widget::XOGrid::drawFrame()
{
    DrawLine(0, 1, WIDTH, 1, BG_PRIMARY);
    DrawLine(1, 0, 1, WIDTH, BG_PRIMARY);
    DrawLine(WIDTH, 0, WIDTH, WIDTH, BG_PRIMARY);
    DrawLine(0, WIDTH, WIDTH, WIDTH, BG_PRIMARY);
}

void widget::XOGrid::drawSeparators()
{
    for (auto i = 1; i < _xo->size(); i++)
    {
        DrawLine(cellSize() * i, 0, cellSize() * i, WIDTH, BG_PRIMARY);
        DrawLine(0, cellSize() * i, WIDTH, cellSize() * i, BG_PRIMARY);
    }
}

void widget::XOGrid::drawCells()
{
    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            _cells[i][j].draw();
}
