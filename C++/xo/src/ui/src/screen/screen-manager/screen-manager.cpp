#include "screen-manager.hpp"
#include "screen.hpp"

void screen::ScreenManager::switchTo(std::unique_ptr<screen::Screen> screen)
{
    _current = std::move(screen);
    _current->setScreenManager(this);
}

void screen::ScreenManager::draw(const gfx::Renderer &renderer) const
{
    _current->draw(renderer);
}
