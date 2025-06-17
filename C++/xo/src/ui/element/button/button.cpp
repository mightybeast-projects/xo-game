#include "button.hpp"
#include "raygui.h"

using namespace element;

void Button::draw()
{
    const int res = GuiButton(_rect, _text.c_str());

    if (res == 1)
        isPressed = true;
}
