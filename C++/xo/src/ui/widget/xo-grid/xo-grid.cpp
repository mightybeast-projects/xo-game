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

    _xo->placeNext(0, 0);
    _cells[0][0].setValue(_xo->state()[0][0].value());

    _xo->placeNext(0, 2);
    _cells[0][2].setValue(_xo->state()[0][2].value());

    _xo->placeNext(1, 1);
    _cells[1][1].setValue(_xo->state()[1][1].value());
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

    auto padding = 4;

    for (auto i = 0; i < _xo->size(); i++)
    {
        for (auto j = 0; j < _xo->size(); j++)
        {
            auto x = cellSize() * i + padding;
            auto y = cellSize() * j + padding;
            auto size = cellSize() - padding * 2;
            auto value = _xo->state()[i][j];

            _cells[i][j] = widget::Cell(x, y, size, value);
        }
    }
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
