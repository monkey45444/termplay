#pragma once

#include "types.h"

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
    void set_position(const Point& p);
    void set_alt_buf(bool enable);
    void set_cursor_visible(bool enable);
    void set_echo_mode(bool enable);
    void set_canonical_mode(bool enable);
    void set_locale();
}
