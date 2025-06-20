#pragma once

#include "raylib.h"
#include "string"
#include "functional"
#include "drawable.hpp"

namespace widget
{
    struct Button : common::Drawable
    {
        Button(Rectangle rect, std::string text) : _rect(rect), _text(text) {};

        void draw();

        void onClick(std::function<void()> cb)
        {
            _onClick = cb;
        }

    private:
        Rectangle _rect;
        std::string _text;
        std::function<void()> _onClick;
    };
}