#include "button.hpp"
#include "raygui.h"

void widget::Button::draw()
{
    GuiButton(_rect, _text.c_str());

    if (_onClickCb && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, _rect))
            _onClickCb();
    }
}
