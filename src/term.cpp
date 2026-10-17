#include "term.h"

#include <cwchar>
#include <cstdio>
#include <clocale>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

static Color default_color;

char term::get_char(){
    return getchar();
}
Point term::get_size(){
    winsize w;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
        return {};
    return Point{w.ws_col, w.ws_row};
}
Color term::get_default_color(){
    return default_color;
}
void term::write(wchar_t glyph){
    wprintf(L"%lc", glyph);
}
void term::write(const wchar_t* str){
    wprintf(L"%ls", str);
}
void term::set_color(Color c){
    wprintf(L"\033[%u;%um", c.fg, c.bg);
}
void term::set_color(uint16_t c){
    wprintf(L"\033[%um", c);
}
void term::set_color(uint16_t fg, uint16_t bg){
    wprintf(L"\033[%u;%um", fg, bg);
}
void term::set_position(const Point& p){
    wprintf(L"\033[%d;%dH", p.y + 1, p.x + 1);
}

void term::set_alt_buf(bool enable){
    if(enable)
        term::write(L"\033[?1049h");
    else
        term::write(L"\033[?1049l");
}
void term::set_cursor_visible(bool enable){
    if(enable)
        term::write(L"\033[?25h");
    else
        term::write(L"\033[?25l");
}
void term::set_echo_mode(bool enable){
    termios mode;
    tcgetattr(STDIN_FILENO, &mode);
    if(enable)
        mode.c_lflag |= ECHO;
    else
        mode.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &mode);
}
void term::set_canonical_mode(bool enable){
    termios mode;
    tcgetattr(STDIN_FILENO, &mode);
    if(enable)
        mode.c_lflag |= ICANON;
    else
        mode.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &mode);
}
void term::set_locale(){
    std::setlocale(LC_ALL,"");
}

void term::reset_color(){
    term::set_color(default_color);
}
void term::clear(){
    term::set_color(default_color);
    term::write(L"\033[2J");
}

void term::set_playmode(bool enable){
    if(enable){
        set_locale();
        set_alt_buf(true);
        set_cursor_visible(false);
        set_echo_mode(false);
        set_canonical_mode(false);
        clear();
    }
    else{
        set_canonical_mode(true);
        set_echo_mode(true);
        set_cursor_visible(true);
        set_alt_buf(false);
    }
}
