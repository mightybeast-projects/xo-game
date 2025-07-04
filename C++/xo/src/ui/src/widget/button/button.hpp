#pragma once

#include "string"
#include "functional"
#include "drawable.hpp"
#include "clickable.hpp"
#include <memory>
#include "renderer.hpp"

namespace widget
{
    struct Button : common::Clickable, common::Drawable
    {
        Button(Rect rect, std::string text, std::function<void()> onClick)
            : _rect(rect), _text(text), common::Clickable(onClick) {};

        void draw(const gfx::Renderer &renderer) override;

    private:
        Rect _rect;
        std::string _text;
    };
}