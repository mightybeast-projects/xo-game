#include "xo.hpp"

xo::XO::XO(int size) : _size(size)
{
    _cells.resize(size);

    for (auto i = 0; i < size; i++)
        _cells[i].resize(size, std::nullopt);
}

bool xo::XO::placeNext(int i, int j)
{
    const auto res = place(i, j, _nextValue);

    if (!res)
        return false;

    if (_nextValue == X)
        _nextValue = O;
    else if (_nextValue == O)
        _nextValue = X;

    return true;
}

bool xo::XO::place(int i, int j, XOValue value)
{
    const auto oob = (i < 0 || i >= _size) || (j < 0 || j >= _size);

    if (_winner.has_value() || oob || _cells[i][j].has_value())
        return false;

    _cells[i][j] = value;

    checkWinConditions();

    return true;
}

bool xo::XO::checkWinConditions()
{
    const int directions[8][4] = { { 0, 0, 1, 1 },
        { 0, 2, 1, -1 },
        { 0, 0, 0, 1 },
        { 1, 0, 0, 1 },
        { 2, 0, 0, 1 },
        { 0, 0, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 2, 1, 0 } };

    for (auto d : directions)
    {
        if (checkLine(d[0], d[1], d[2], d[3]))
        {
            _winner = _cells[d[0]][d[1]];
            return true;
        }
    }

    return false;
}

bool xo::XO::checkLine(int startI, int startJ, int iIncrement, int jIncrement)
{
    int i = startI;
    int j = startJ;

    if (!_cells[i][j].has_value())
        return false;

    XOValue value = _cells[i][j].value();

    for (auto k = 0; k < _size; k++, i += iIncrement, j += jIncrement)
        if (!_cells[i][j].has_value() || _cells[i][j] != value)
            return false;

    return true;
}

bool xo::XO::allCellsAreOccupied() const
{
    for (auto i = 0; i < _size; i++)
        for (auto j = 0; j < _size; j++)
            if (!_cells[i][j].has_value())
                return false;

    return true;
}
