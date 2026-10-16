#pragma once

#include <cstdint>

struct Point{
    int x, y;
};
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
        fg_while = 37,
        bg_black = 40,
        bg_red = 41,
        bg_green = 42,
        bg_yellow = 43,
        bg_blue = 44,
        bg_purple = 45,
        bg_cyan = 46,
        bg_while = 47
    };
};

namespace term{
    char get_char();
    Point get_size();
    Color get_default_color();

    void write(wchar_t glyph);
    void write(const wchar_t* str);

    void set_color(Color c);
    void set_color(uint16_t c);
    void set_color(uint16_t fg, uint16_t bg);
    void reset_color();
    void clear();

    void set_playmode(bool enable);
    void set_position(const Point& new_pos);
    void set_alt_buf(bool enable);
    void set_cursor_visible(bool enable);
    void set_echo_mode(bool enable);
    void set_canonical_mode(bool enable);
    void set_locale();
}
