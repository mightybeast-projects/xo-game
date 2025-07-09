#include "xo-grid.hpp"
#include "cell.hpp"
#include "config.hpp"
#include "raylib-renderer.hpp"
#include "types.hpp"
#include "xo.hpp"
#include <optional>
#include <string>

widget::XOGrid::XOGrid(xo::XO* xo) : _xo(xo)
{
    _cells.resize(_xo->size());

    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            initCell(i, j);
}

void widget::XOGrid::draw(const gfx::Renderer& renderer) const
{
    for (auto i = 0; i < _xo->size(); i++)
        for (auto j = 0; j < _xo->size(); j++)
            _cells[i][j]->draw(renderer);
}

void widget::XOGrid::initCell(int i, int j)
{
    const float padding = 5;
    const float x = cellSize() * i + padding;
    const float y = cellSize() * j + padding;
    const float size = cellSize() - padding * 2;
    const Rect rect = { x, y, size, size };

    auto cell = std::make_unique<widget::Cell>(rect);

    cell->onClick([this, i, j]() {
        auto tilePlaced = _xo->placeNext(i, j);

        if (tilePlaced)
            _cells[i][j]->setValue(_xo->cells()[i][j].value());

        if (_onAfterTileClick)
            _onAfterTileClick();
    });

    _cells[i].push_back(std::move(cell));
}
