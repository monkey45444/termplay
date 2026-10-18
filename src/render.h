#pragma once

#include "types.h"
#include <vector>

class Render{
private:
    Point window_size;
    Point brush_pos;
    RGB brush_color;
    RGB tile_fg_color;
    RGB tile_bg_color;
    std::vector<RGB> color_vec;
    std::vector<uint8_t> dirty_vec;

    RGB& get_color_at(Point p);
    uint8_t& get_dirty_at(Point p);
    void reset_brush_pos();
    void write_glyph(Point p, wchar_t glyph);

public:
    void init();
    void terminate();
    void update();

    void set_color(RGB c);
    void write(Point p);
    char get_char() const;
};
