#include "screen-manager.hpp"

void screen::ScreenManager::switchTo(screen::Screen *screen)
{
    _current.reset(screen);
    screen->setScreenManager(this);
}

void screen::ScreenManager::draw()
{
    _current->draw();
}
