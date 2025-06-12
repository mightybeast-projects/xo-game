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
    const auto indexesAreOutOfBounds = (i < 0 || i >= size) || (j < 0 || j >= size);

    if (indexesAreOutOfBounds || value == EMPTY || arr[i][j] != EMPTY)
        return;

    arr[i][j] = value;
}

bool XO::checkWin()
{
    auto diagonal1 = checkLine(0, 0, 1, 1);
    auto diagonal2 = checkLine(0, 2, 1, -1);

    return diagonal1 || diagonal2;
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