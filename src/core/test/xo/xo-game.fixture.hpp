#pragma once

#include "xo.hpp"
#include <gtest/gtest.h>

struct XOGame : public testing::Test
{
    xo::XO xo = xo::XO(3);
};