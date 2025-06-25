#include "screen-manager.hpp"
#include "screen.hpp"

void screen::ScreenManager::switchTo(screen::Screen *screen)
{
    _current.reset(screen);
    screen->setScreenManager(this);
}

void screen::ScreenManager::draw()
{
    _current->draw();
}
