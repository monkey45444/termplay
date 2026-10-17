#include "types.h"

Point::Point(): x(0), y(0){}
Point::Point(int x, int y): x(x), y(y){}
Point::Point(const Point& p): x(p.x), y(p.y){}

Point& Point::operator=(const Point& p){
    this->x = p.x;
    this->y = p.y;
    return *this;
}
bool operator==(const Point& p1, const Point& p2){
    return p1.x == p2.x && p1.y == p2.y;
}
bool operator!=(const Point& p1, const Point& p2){
    return p1.x != p2.x || p1.y != p2.y;
}

Color::Color(): fg(Color::fg_black), bg(Color::bg_black){}
Color::Color(uint16_t fg, uint16_t bg): fg(fg), bg(bg){}
Color::Color(const Color& c): fg(c.fg), bg(c.bg){}

bool operator==(const Color& c1, const Color& c2){
    return c1.fg == c2.fg && c1.bg == c2.bg;
}
bool operator!=(const Color& c1, const Color& c2){
    return c1.fg != c2.fg || c1.bg != c2.bg;
}
