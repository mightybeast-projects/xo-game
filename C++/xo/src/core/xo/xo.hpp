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

        void place(int i, int j, XOValue value);

    private:
        int size;
        std::vector<std::vector<XOValue>> arr;
    };
}