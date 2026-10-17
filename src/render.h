#pragma once

#include "types.h"
#include <vector>

class Render{
private:
    Point cur_w_size;
    Point brush_pos;
    Color brush_color;
    std::vector<Color> color_vec;
    std::vector<uint8_t> change_vec;

    Color& get_color_from_vec(Point p);
    uint8_t& get_change_from_vec(Point p);

public:
    Render();
    ~Render();

    void init();
    void terminate();
    void update();

    void set_color(Color c);
    void write(int x, int y);
    void write(Point p);
    char get_char();
};
