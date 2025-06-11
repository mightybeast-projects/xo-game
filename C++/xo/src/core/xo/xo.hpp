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

    private:
        int size;
        XOValue nextValue = X;
        std::vector<std::vector<XOValue>> arr;
    };
}