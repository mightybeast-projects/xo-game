#include <gtest/gtest.h>
#include "o.hpp"

widget::O o = widget::O(1, 1, 1);

TEST(SampleTest, ShouldPass11)
{
    EXPECT_EQ(1, 1);
}