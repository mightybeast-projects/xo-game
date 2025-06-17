#include "raylib.h"
#include "config.hpp"

namespace widget
{
    struct X
    {
        X() {}
        X(int x, int y, int size) : x(x), y(y), size(size) {}

        inline void draw()
        {
            DrawLine(x, y, x + size, y + size, CROSS);
            DrawLine(x + size, y, x, y + size, CROSS);
        }

    private:
        int x;
        int y;
        int size;
    };
}