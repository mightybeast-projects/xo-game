#pragma once

struct Col
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    friend bool operator==(const Col &lhs, const Col &rhs)
    {
        return lhs.r == rhs.r &&
               lhs.g == rhs.g &&
               lhs.b == rhs.b &&
               lhs.a == rhs.a;
    }
};

struct Rect
{
    float x;
    float y;
    float width;
    float height;
};