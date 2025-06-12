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

        void placeNext(int i, int j);
        void place(int i, int j, XOValue value);
        bool checkWin();

    private:
        const int size;
        XOValue nextValue = EMPTY;
        std::vector<std::vector<XOValue>> arr;

        bool checkLine(int startI, int startJ, int iIncrement, int jIncrement);
    };
}