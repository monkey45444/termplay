#pragma once

#include <cstdint>

struct Point{
    int x, y;
    Point();
    Point(int x, int y);
};
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);
bool operator<(const Point& p1, const Point& p2);
bool operator>=(const Point& p, const int& num);
Point operator+(const Point& p1, const Point& p2);

struct RGB{
    uint8_t r, g, b;
    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
};
bool operator==(const RGB& c1, const RGB& c2);
bool operator!=(const RGB& c1, const RGB& c2);
