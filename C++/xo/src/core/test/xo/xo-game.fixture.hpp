#pragma once

#include <gtest/gtest.h>
#include "xo.hpp"

struct XOGame : public testing::Test
{
    xo::XO xo = xo::XO(3);
};