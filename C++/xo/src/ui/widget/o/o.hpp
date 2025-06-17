#include "raylib.h"
#include "config.hpp"

namespace widget
{
    struct O
    {
        O() {}
        O(int x, int y, int radius) : x(x), y(y), radius(radius) {}

        inline void draw()
        {
            DrawCircleLines(x, y, radius * 1.3, CIRCLE);
        }

    private:
        int x;
        int y;
        int radius;
    };
}