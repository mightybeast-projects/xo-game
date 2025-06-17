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

        void placeNext(int i, int j);
        void place(int i, int j, XOValue value);

        inline int size() const
        {
            return _size;
        }

        inline std::optional<XOValue> winner() const
        {
            return _winner;
        }

        inline const std::vector<std::vector<std::optional<XOValue>>> &state() const
        {
            return _state;
        }

    private:
        int _size;
        XOValue _nextValue = X;
        std::optional<XOValue> _winner = std::nullopt;
        std::vector<std::vector<std::optional<XOValue>>> _state;

        bool checkWinConditions();
        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
    };
}