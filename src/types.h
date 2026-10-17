#pragma once

#include <cstdint>

struct Point{
    int x, y;
    Point();
    Point(int x, int y);
    Point(const Point& p);

    Point& operator=(const Point& p);
};
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);

struct Color{
    uint16_t fg, bg;
    enum Colors : uint16_t {
        fg_black = 30,
        fg_red = 31,
        fg_green = 32,
        fg_yellow = 33,
        fg_blue = 34,
        fg_purple = 35,
        fg_cyan = 36,
        fg_white = 37,
        bg_black = 40,
        bg_red = 41,
        bg_green = 42,
        bg_yellow = 43,
        bg_blue = 44,
        bg_purple = 45,
        bg_cyan = 46,
        bg_white = 47
    };
    Color();
    Color(uint16_t fg, uint16_t bg);
    Color(const Color& c);
};

bool operator==(const Color& c1, const Color& c2);
bool operator!=(const Color& c1, const Color& c2);
