#include "xo.hpp"

using namespace xo;

void XO::placeNext(int i, int j)
{
    place(i, j, nextValue);

    if (nextValue == X)
        nextValue = O;
    else if (nextValue == O)
        nextValue = X;
}

void XO::place(int i, int j, XOValue value)
{
    const auto oob = (i < 0 || i >= size) || (j < 0 || j >= size);

    if (winner != EMPTY || oob || value == EMPTY || arr[i][j] != EMPTY)
        return;

    arr[i][j] = value;

    checkWinConditions();
}

bool XO::checkWinConditions()
{
    winner = EMPTY;

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
            winner = arr[d[0]][d[1]];
            return true;
        }
    }

    return false;
}

bool XO::checkLine(int startI, int startJ, int iIncrement, int jIncrement)
{
    int i = startI;
    int j = startJ;
    XOValue value = arr[i][j];

    for (auto k = 0; k < size; k++, i += iIncrement, j += jIncrement)
        if (arr[i][j] == EMPTY || arr[i][j] != value)
            return false;

    return true;
}