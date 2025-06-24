#include "clickable.hpp"

void common::Clickable::handleClick(Rectangle rect)
{
    if (_onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        const Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, rect))
            _onClick();
    }
}