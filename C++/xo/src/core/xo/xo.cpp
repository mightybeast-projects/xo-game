#include "xo.hpp"

using namespace xo;
using namespace std;

XO::XO(int size)
{
    _size = size;
    _state.resize(size);

    for (auto i = 0; i < size; i++)
        _state[i].resize(size, nullopt);
}

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

    if (_winner.has_value() || oob || _state[i][j].has_value())
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

    for (auto d : directions)
    {
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

    if (!_state[i][j].has_value())
        return false;

    XOValue value = _state[i][j].value();

    for (auto k = 0; k < _size; k++, i += iIncrement, j += jIncrement)
        if (!_state[i][j].has_value() || _state[i][j] != value)
            return false;

    return true;
}