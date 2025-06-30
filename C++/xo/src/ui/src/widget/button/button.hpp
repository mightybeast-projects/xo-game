#pragma once

#include "string"
#include "functional"
#include "drawable.hpp"
#include "clickable.hpp"
#include <memory>
#include "renderer.hpp"

namespace widget
{
    struct Button : common::Clickable
    {
        Button(Rect rect,
               std::string text,
               gfx::Renderer *renderer,
               std::function<void()> onClick) : _rect(rect),
                                                _text(text),
                                                common::Clickable(renderer, onClick) {};

        void draw() override;

    private:
        Rect _rect;
        std::string _text;
    };
}