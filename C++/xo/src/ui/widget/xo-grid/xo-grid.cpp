#include "xo-grid.hpp"
#include "xo.hpp"
#include "config.hpp"

widget::XOGrid::XOGrid(int size)
{
    _xo = std::make_unique<xo::XO>(size);
}

void widget::XOGrid::draw()
{
    drawFrame();
    drawSeparators();
    drawCells();
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
            Rectangle rect = {cellSize() * i + padding,
                              cellSize() * j + padding,
                              cellSize() - padding * 2,
                              cellSize() - padding * 2};

            DrawRectangleRounded(rect, 0.1, 0, BG_SECONDARY);
        }
    }
}
