#include <vector>
#include <optional>

namespace xo
{
    enum XOValue
    {
        EMPTY,
        X,
        O
    };

    struct XO
    {
        XO(int size) : _size(size),
                       _state(size, std::vector<XOValue>(size, EMPTY)) {};

        void placeNext(int i, int j);
        void place(int i, int j, XOValue value);

        inline const std::vector<std::vector<XOValue>> &state() const
        {
            return _state;
        }

        inline int size() const
        {
            return _size;
        }

        inline std::optional<XOValue> winner() const
        {
            return _winner;
        }

    private:
        const int _size;
        XOValue _nextValue = X;
        std::optional<XOValue> _winner = std::nullopt;
        std::vector<std::vector<XOValue>> _state;

        bool checkWinConditions();
        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
    };
}