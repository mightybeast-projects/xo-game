#include "xo.hpp"

using namespace xo;

void XO::placeNext(int i, int j)
{
    if (nextValue == X)
        nextValue = O;
    else if (nextValue == EMPTY || nextValue == O)
        nextValue = X;

    place(i, j, nextValue);
}

void XO::place(int i, int j, XOValue value)
{
    const auto oob = (i < 0 || i >= size) || (j < 0 || j >= size);

    if (checkWin() || oob || value == EMPTY || arr[i][j] != EMPTY)
        return;

    arr[i][j] = value;
}

bool XO::checkWin()
{
    auto d1 = checkLine(0, 0, 1, 1);
    auto d2 = checkLine(0, 2, 1, -1);

    auto v1 = checkLine(0, 0, 0, 1);
    auto v2 = checkLine(1, 0, 0, 1);
    auto v3 = checkLine(2, 0, 0, 1);

    auto h1 = checkLine(0, 0, 1, 0);
    auto h2 = checkLine(0, 1, 1, 0);
    auto h3 = checkLine(0, 2, 1, 0);

    return d1 || d2 || v1 || v2 || v3 || h1 || h2 || h3;
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