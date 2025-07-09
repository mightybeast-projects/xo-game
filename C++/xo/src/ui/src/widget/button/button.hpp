#pragma once

#include "clickable.hpp"
#include "drawable.hpp"
#include "functional"
#include "renderer.hpp"
#include "string"
#include <memory>

namespace widget
{
    struct Button : common::Clickable, common::Drawable
    {
        Button(Rect rect, std::string text, std::function<void()> onClick)
            : _rect(rect), _text(text), common::Clickable(onClick) { };

        void draw(const gfx::Renderer& renderer) const override;

    private:
        const Rect _rect;
        const std::string _text;
    };
}