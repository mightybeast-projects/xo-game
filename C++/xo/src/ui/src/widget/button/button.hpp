#pragma once

#include "string"
#include "functional"
#include "drawable.hpp"
#include "clickable.hpp"

namespace widget
{
    struct Button : common::Drawable, common::Clickable
    {
        Button(
            Rect rect,
            std::string text,
            std::function<void()> onClick) : _rect(rect),
                                             _text(text),
                                             common::Clickable(onClick) {};

        void draw() override;

    private:
        Rect _rect;
        std::string _text;
    };
}