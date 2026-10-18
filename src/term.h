#pragma once

#include "types.h"

namespace term{
    char get_char();
    Point get_size();
    RGB get_default_color();

    void write(wchar_t glyph);
    void write(const wchar_t* str);

    void set_fg_color(RGB c);
    void set_bg_color(RGB c);
    void set_color(RGB fg, RGB bg);
    void reset_color();
    void clear();

    void set_playmode(bool enable);
    void set_position(const Point& p);
    void set_alt_buf(bool enable);
    void set_cursor_visible(bool enable);
    void set_echo_mode(bool enable);
    void set_canonical_mode(bool enable);
    void set_locale();
}
