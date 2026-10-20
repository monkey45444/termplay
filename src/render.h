#pragma once

#include "types.h"
#include <vector>

class Render{
private:
    enum class UpdateState : uint8_t{
        unchanged = 0,
        update = 1,
        erase = 2
    };

    Point window_size;
    Point brush_pos;
    RGB brush_color;
    RGB tile_fg_color;
    RGB tile_bg_color;
    RGB default_color;
    std::vector<RGB> color_vec;
    std::vector<UpdateState> dirty_vec;

    RGB& get_color_at(Point p);
    UpdateState& get_dirty_at(Point p);
    void reset_brush_pos();
    void write_glyph(Point p, wchar_t glyph);
    void update_glyph(Point p);
    void process_tile(RGB& c, UpdateState& u);

public:
    void init();
    void terminate();
    void update();

    void set_color(RGB c);
    void write(Point p);
    char get_char() const;
};
