#include "restart-dialog.hpp"
#include <string>

void widget::RestartDialog::draw(const gfx::Renderer &renderer)
{
    if (_isHidden)
        return;

    std::string message;

    if (_xo->winner().has_value() && _xo->winner() == xo::X)
        message = "X player won!";
    if (_xo->winner().has_value() && _xo->winner() == xo::O)
        message = "O player won!";
    if (_xo->isDraw())
        message = "Draw!";

    const Rect r = {85, 70, 250, 100};
    const char *title = "#191#Game over!";
    const char *btnLables = "Restart;Quit";

    const auto box = renderer.drawGuiMessageBox(r, title, message, btnLables);

    if (box == 1)
        _onRestart();
    if (box == 2)
        _onQuit();
}