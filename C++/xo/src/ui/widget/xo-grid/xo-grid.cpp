#include "xo-grid.hpp"
#include "xo.hpp"
#include "raygui.h"
#include "config.hpp"
#include "x.hpp"
#include "cell.hpp"
#include <optional>
#include <string>

widget::XOGrid::XOGrid(int size)
{
    initGame(size);
}

void widget::XOGrid::draw()
{
    drawFrame();
    drawSeparators();
    drawCells();

    if (_xo->isDraw() || _xo->winner().has_value())
        drawRestartDialog();
}

void widget::XOGrid::initGame(int size)
{
    _xo = std::make_unique<xo::XO>(size);

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
    auto value = _xo->cells()[i][j];

    auto cb = [this, i, j]()
    {
        auto res = _xo->placeNext(i, j);

        if (res)
            _cells[i][j].setValue(_xo->cells()[i][j].value());
    };

    _cells[i][j] = widget::Cell(x, y, size, value, cb);
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

void widget::XOGrid::drawRestartDialog()
{
    std::string message;

    if (_xo->winner().has_value() && _xo->winner() == xo::X)
        message = "X player won!";
    if (_xo->winner().has_value() && _xo->winner() == xo::O)
        message = "O player won!";
    if (_xo->isDraw())
        message = "Draw!";

    const Rectangle r = {85, 70, 250, 100};
    const char *title = "#191#Game over!";
    const char *btnLables = "Restart;Quit";

    const auto box = GuiMessageBox(r, title, message.c_str(), btnLables);

    if (box == 1)
        initGame(_xo->size());
}
