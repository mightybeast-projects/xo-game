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
        Button(Rectangle rect, std::string text, std::function<void()> onClick)
            : _rect(rect), _text(text), common::Clickable(onClick) {};

        void draw();

    private:
        Rectangle _rect;
        std::string _text;
    };
}