#include "clickable.hpp"
#include "rect.hpp"
#include "raylib.h"

void common::Clickable::handleClick(Rect r)
{
    if (_onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        const Vector2 mousePos = GetMousePosition();
        const Rectangle rect = {r.x,
                                r.y,
                                r.width,
                                r.height};

        if (CheckCollisionPointRec(mousePos, rect))
            _onClick();
    }
}