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
    if (value != EMPTY)
        arr[i][j] = value;
}