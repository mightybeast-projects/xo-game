#include "xo.hpp"

using namespace xo;

void XO::placeNext(int i, int j)
{
    place(i, j, _nextValue);

    if (_nextValue == X)
        _nextValue = O;
    else if (_nextValue == O)
        _nextValue = X;
}

void XO::place(int i, int j, XOValue value)
{
    const auto oob = (i < 0 || i >= _size) || (j < 0 || j >= _size);

    if (_winner.has_value() || oob || value == EMPTY || _state[i][j] != EMPTY)
        return;

    _state[i][j] = value;

    checkWinConditions();
}

bool XO::checkWinConditions()
{
    int directions[8][4] = {
        {0, 0, 1, 1},
        {0, 2, 1, -1},
        {0, 0, 0, 1},
        {1, 0, 0, 1},
        {2, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 2, 1, 0}};

    for (auto i = 0; i < 8; i++)
    {
        auto d = directions[i];

        if (checkLine(d[0], d[1], d[2], d[3]))
        {
            _winner = _state[d[0]][d[1]];
            return true;
        }
    }

    return false;
}

bool XO::checkLine(int startI, int startJ, int iIncrement, int jIncrement)
{
    int i = startI;
    int j = startJ;
    XOValue value = _state[i][j];

    for (auto k = 0; k < _size; k++, i += iIncrement, j += jIncrement)
        if (_state[i][j] == EMPTY || _state[i][j] != value)
            return false;

    return true;
}