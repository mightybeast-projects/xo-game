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