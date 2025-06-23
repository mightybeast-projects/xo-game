#pragma once

#include "raylib.h"
#include "string"
#include "functional"
#include "drawable.hpp"
#include "clickable.hpp"

namespace widget
{
    struct Button : common::Drawable, common::Clickable
    {
        Button(Rectangle rect, std::string text) : _rect(rect), _text(text) {};

        void draw();

    private:
        Rectangle _rect;
        std::string _text;
    };
}