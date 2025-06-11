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

        const std::vector<std::vector<XOValue>> &state() const { return arr; }
        int getSize() const { return size; }

    private:
        int size;
        std::vector<std::vector<XOValue>> arr;
    };
}