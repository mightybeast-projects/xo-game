#pragma once

#include "raylib.h"
#include "string"

namespace widget
{
    struct Button
    {
        Button(Rectangle rect, std::string text) : _rect(rect), _text(text) {};

        void draw();

    private:
        Rectangle _rect;
        std::string _text;
    };
}