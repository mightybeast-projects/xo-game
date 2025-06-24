#pragma once

#include <vector>
#include <optional>

namespace xo
{
    enum XOValue
    {
        X,
        O
    };

    struct XO
    {
        XO(int size);

        bool placeNext(int i, int j);
        bool place(int i, int j, XOValue value);

        inline int size() const
        {
            return _size;
        }

        inline const std::optional<XOValue> winner() const
        {
            return _winner;
        }

        inline const std::vector<std::vector<std::optional<XOValue>>> &cells() const
        {
            return _cells;
        }

        inline const bool isDraw()
        {
            return allCellsAreOccupied() && !_winner.has_value();
        }

    private:
        int _size;
        XOValue _nextValue = X;
        std::optional<XOValue> _winner = std::nullopt;
        std::vector<std::vector<std::optional<XOValue>>> _cells;

        bool checkWinConditions();
        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
        bool allCellsAreOccupied();
    };
}