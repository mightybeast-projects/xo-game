#include "xo-grid.hpp"
#include "xo.hpp"
#include "config.hpp"
#include "x.hpp"
#include "cell.hpp"

widget::XOGrid::XOGrid(int size)
{
    _xo = std::make_unique<xo::XO>(size);
}

void widget::XOGrid::draw()
{
    drawFrame();
    drawSeparators();
    drawCells();

    widget::X x = widget::X(cellSize() / 4, cellSize() / 4, cellSize());

    x.draw();
}

void widget::XOGrid::drawFrame()
{
    DrawLine(0, 1, WIDTH, 1, PRIMARY);
    DrawLine(1, 0, 1, WIDTH, PRIMARY);
    DrawLine(WIDTH, 0, WIDTH, WIDTH, PRIMARY);
    DrawLine(0, WIDTH, WIDTH, WIDTH, PRIMARY);
}

void widget::XOGrid::drawSeparators()
{
    for (auto i = 1; i < _xo->size(); i++)
    {
        DrawLine(cellSize() * i, 0, cellSize() * i, WIDTH, PRIMARY);
        DrawLine(0, cellSize() * i, WIDTH, cellSize() * i, PRIMARY);
    }
}

void widget::XOGrid::drawCells()
{
    auto padding = 4;

    for (auto i = 0; i < _xo->size(); i++)
    {
        for (auto j = 0; j < _xo->size(); j++)
        {
            auto x = cellSize() * i + padding;
            auto y = cellSize() * j + padding;
            auto size = cellSize() - padding * 2;

            widget::Cell cell = widget::Cell(x, y, size);

            cell.draw();
        }
    }
}
