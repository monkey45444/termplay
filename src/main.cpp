#include "render.h"

Render r;

void print_rectangle(Point pos, Point size){
    Point p1 = pos;
    Point p2 = Point(pos.x + size.x, pos.y);
    for(; p1.x < p2.x; p1.x++)
        r.write(p1);
    p1 = Point(pos.x, pos.y + size.y - 1);
    p2 = Point(pos.x + size.x, pos.y);
    for(; p1.x < p2.x; p1.x++)
        r.write(p1);
    p1 = Point(pos.x, pos.y + 1);
    p2 = Point(pos.x, pos.y + size.y - 1);
    for(; p1.y < p2.y; p1.y++)
        r.write(p1);
    p1 = Point(pos.x + size.x - 1, pos.y + 1);
    p2 = Point(pos.x, pos.y + size.y - 1);
    for(; p1.y < p2.y; p1.y++)
        r.write(p1);
}
int main(){
    r.init();
    r.set_color(RGB(255, 0, 0));
    print_rectangle(Point(3, 3), Point(10, 10));
    r.set_color(RGB(0, 0, 255));
    print_rectangle(Point(5, 5), Point(10, 10));
    r.update();
    r.get_char();
    r.terminate();
}
