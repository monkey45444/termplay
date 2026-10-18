#include "types.h"

Point::Point(): x(0), y(0){}
Point::Point(int x, int y): x(x), y(y){}
bool operator==(const Point& p1, const Point& p2){
    return p1.x == p2.x && p1.y == p2.y;
}
bool operator!=(const Point& p1, const Point& p2){
    return p1.x != p2.x || p1.y != p2.y;
}

RGB::RGB(): r(0), g(0), b(0){}
RGB::RGB(uint8_t r, uint8_t g, uint8_t b): r(r), g(g), b(b){}
bool operator==(const RGB& c1, const RGB& c2){
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b;
}
bool operator!=(const RGB& c1, const RGB& c2){
    return c1.r != c2.r || c1.g != c2.g || c1.b != c2.b;
}
bool operator<(const Point& p1, const Point& p2){
    return p1.x < p2.x && p1.y < p2.y;
}
bool operator>=(const Point& p, const int& num){
    return p.x >= num && p.y >= num;
}
Point operator+(const Point& p1, const Point& p2){
    return Point(p1.x + p2.x, p1.y + p2.y);
}
