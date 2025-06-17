#include "xo-grid.hpp"
#include "xo.hpp"
#include "config.hpp"

widget::XOGrid::XOGrid(int size)
{
    _xo = new xo::XO(size);
}

void widget::XOGrid::draw()
{
    float cellSize = WIDTH / _xo->size();

    for (auto i = 1; i < _xo->size(); i++)
    {
        DrawLine(cellSize * i, 0, cellSize * i, WIDTH, CELL);
        DrawLine(0, cellSize * i, WIDTH, cellSize * i, CELL);
    }
}