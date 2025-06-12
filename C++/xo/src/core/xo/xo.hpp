#include <vector>

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

        inline const std::vector<std::vector<XOValue>> &state() const
        {
            return arr;
        }

        inline int getSize() const
        {
            return size;
        }

        inline bool finished() const
        {
            return winner != EMPTY;
        }

        inline XOValue getWinner() const
        {
            return winner;
        }

        void placeNext(int i, int j);
        void place(int i, int j, XOValue value);

    private:
        const int size;
        XOValue nextValue = X;
        XOValue winner = EMPTY;
        std::vector<std::vector<XOValue>> arr;

        bool checkWinConditions();
        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
    };
}