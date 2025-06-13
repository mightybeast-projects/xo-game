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
        XO(int size) : size(size),
                       arr(size, std::vector<XOValue>(size, EMPTY)) {};

        void placeNext(int i, int j);
        void place(int i, int j, XOValue value);

        inline const std::vector<std::vector<XOValue>> &state() const
        {
            return arr;
        }

        inline int getSize() const
        {
            return size;
        }

        inline std::optional<XOValue> getWinner() const
        {
            return winner;
        }

    private:
        const int size;
        XOValue nextValue = X;
        std::optional<XOValue> winner = std::nullopt;
        std::vector<std::vector<XOValue>> arr;

        bool checkWinConditions();
        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
    };
}