#pragma once

#include "string"
#include "functional"
#include "drawable.hpp"
#include "clickable.hpp"
#include <memory>
#include "renderer.hpp"

namespace widget
{
    struct Button : common::Drawable, common::Clickable
    {
        Button(
            Rect rect,
            std::string text,
            std::shared_ptr<gfx::Renderer> renderer,
            std::function<void()> onClick) : _rect(rect),
                                             _text(text),
                                             common::Drawable(renderer),
                                             common::Clickable(onClick) {};

        void draw() override;

    private:
        Rect _rect;
        std::string _text;
    };
}