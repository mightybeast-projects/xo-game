#include "xo.hpp"

using namespace xo;

void XO::place(int i, int j, XOValue value)
{
    if (value == EMPTY)
        return;

    arr[i][j] = value;
}